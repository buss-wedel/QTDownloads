/**
 ** This file is part of the QTDownloads project.
 ** Copyright 2018 Buss-Wedel <buss-wedel@mail.com>.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/
#include "downloadlistcategorydialog.h"

#include <QPushButton>

DownloadListCategoryDialog::DownloadListCategoryDialog()
{
    createDownloadListCategoryDialogLayout();
    createConnections();

    setWindowTitle(tr("Create a new category"));
}

int DownloadListCategoryDialog::exec()
{
    setFixedDialogSize();
    return QDialog::exec();
}

QString DownloadListCategoryDialog::description() const
{
    return categoryDescriptionPlainTextEdit->toPlainText();
}

QString DownloadListCategoryDialog::name() const
{
    return categoryNameLineEdit->text();
}

void DownloadListCategoryDialog::setData(const QString &name, const QString &description)
{
    categoryNameLineEdit->setText(name);
    categoryDescriptionPlainTextEdit->setPlainText(description);

    setWindowTitle(tr("Edit a category"));
}

QFormLayout *DownloadListCategoryDialog::subFormLayout()
{
    return subLayout;
}

void DownloadListCategoryDialog::createConnections()
{
    connect(categoryDialogButtonBox, &QDialogButtonBox::rejected,
            this, &QDialog::reject);
    connect(categoryDialogButtonBox, &QDialogButtonBox::accepted,
            this, &QDialog::accept);
}

QVBoxLayout *DownloadListCategoryDialog::createSpacingLayout()
{
    QVBoxLayout *spacingLayout = new QVBoxLayout();
    spacingLayout->addSpacing(10);

    return spacingLayout;
}

void DownloadListCategoryDialog::setFixedDialogSize()
{
    setFixedHeight(sizeHint().rheight());
    setMinimumWidth(sizeHint().rwidth());
}

void DownloadListCategoryDialog::createDownloadListCategoryDialogLayout()
{
    categoryNameLineEdit = new QLineEdit();

    categoryDescriptionPlainTextEdit = new QPlainTextEdit();

    subLayout = new QFormLayout();
    subLayout->addRow(tr("Name:"),categoryNameLineEdit);
    subLayout->addRow(tr("Description:"), categoryDescriptionPlainTextEdit);

    categoryDialogButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok |
                                                               QDialogButtonBox::Cancel);
    categoryDialogButtonBox->button(QDialogButtonBox::Ok)
                                       ->setIcon(QIcon(":/icons/apply.png"));
    categoryDialogButtonBox->button(QDialogButtonBox::Cancel)
                                       ->setIcon(QIcon(":/icons/cancel.png"));

    mainLayout = new QVBoxLayout();
    mainLayout->addLayout(subLayout);
    mainLayout->addLayout(createSpacingLayout());
    mainLayout->addWidget(categoryDialogButtonBox);

    setLayout(mainLayout);
}
