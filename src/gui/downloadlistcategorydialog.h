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
#ifndef DOWNLOADLISTCATEGORYDIALOG_H
#define DOWNLOADLISTCATEGORYDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QVBoxLayout>

class DownloadListCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    DownloadListCategoryDialog();

    int exec();

    QString description() const;
    QString name() const;
    void setData(const QString &name, const QString &description);

protected:
    QFormLayout *subFormLayout();
    QVBoxLayout *createSpacingLayout();
    void setFixedDialogSize();

private:
    void createConnections();
    void createDownloadListCategoryDialogLayout();

    QLineEdit *categoryNameLineEdit;

    QPlainTextEdit *categoryDescriptionPlainTextEdit;

    QDialogButtonBox *categoryDialogButtonBox;

    QVBoxLayout *mainLayout;

    QFormLayout *subLayout;
};

#endif // DOWNLOADLISTCATEGORYDIALOG_H
