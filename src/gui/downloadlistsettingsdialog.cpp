#include "downloadlistsettingsdialog.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QGroupBox>
#include <QPushButton>
#include <QFormLayout>


DownloadListSettingsDialog::DownloadListSettingsDialog()
{
    createDownloadListSettingsDialogLayout();
    createConnections();

    setFixedHeight(sizeHint().rheight());
    setMinimumWidth(sizeHint().rwidth());

    setWindowTitle(tr("New download list options"));
}

QString DownloadListSettingsDialog::templateFileName() const
{
    return currentTemplateFileNameLineEdit->text();
}

QString DownloadListSettingsDialog::absoluteFilesPath() const
{
    return absolutePathToDownloadableFilesLineEdit->text();
}

QString DownloadListSettingsDialog::relativeFilesPath() const
{
    return relativePathToDownloadableFilesLineEdit->text();
}

QString DownloadListSettingsDialog::absolutePicturePath() const
{
    return absolutePathToPicturesLineEdit->text();
}

QString DownloadListSettingsDialog::relativePicturePath() const
{
    return relativePathToPicturesLineEdit->text();
}

void DownloadListSettingsDialog::setData(const QString &fileName, const QString &templateFileName, const QString &absoluteFilesPath, const QString &relativeFilesPath, const QString &absolutePicturePath, const QString &relativePicturePath)
{
    currentListFileNameLineEdit->setText(fileName);
    currentTemplateFileNameLineEdit->setText(templateFileName);
    absolutePathToDownloadableFilesLineEdit->setText(absoluteFilesPath);
    relativePathToDownloadableFilesLineEdit->setText(relativeFilesPath);
    absolutePathToPicturesLineEdit->setText(absolutePicturePath);
    relativePathToPicturesLineEdit->setText(relativePicturePath);

    setWindowTitle(tr("Current download list options"));
}

void DownloadListSettingsDialog::createConnections()
{
    connect(downloadListSettingsDialogButtonBox, &QDialogButtonBox::rejected,
            this, &QDialog::reject);
    connect(downloadListSettingsDialogButtonBox, &QDialogButtonBox::accepted,
            this, &QDialog::accept);
}

void DownloadListSettingsDialog::createDownloadListSettingsDialogLayout()
{
    currentListFileNameLineEdit = new QLineEdit();
    currentListFileNameLineEdit->setEnabled(false);

    currentTemplateFileNameLineEdit = new QwwFileChooser();
    currentTemplateFileNameLineEdit->setIcon(QIcon(":/icons/fileopen.png"));

    absolutePathToDownloadableFilesLineEdit = new QwwFileChooser();
    absolutePathToDownloadableFilesLineEdit->setIcon(QIcon(":/icons/fileopen.png"));
    absolutePathToDownloadableFilesLineEdit->setFileMode(QFileDialog::Directory);

    relativePathToDownloadableFilesLineEdit = new QLineEdit();

    absolutePathToPicturesLineEdit = new QwwFileChooser();
    absolutePathToPicturesLineEdit->setIcon(QIcon(":/icons/fileopen.png"));
    absolutePathToPicturesLineEdit->setFileMode(QFileDialog::Directory);

    relativePathToPicturesLineEdit = new QLineEdit();

    QFormLayout *subLayout = new QFormLayout();
    subLayout->addRow(new QLabel(tr("General paths")));
    subLayout->addRow(tr("Current file:"), currentListFileNameLineEdit);
    subLayout->addRow(tr("Current &template:"), currentTemplateFileNameLineEdit);
    subLayout->addRow(createSpacingLayout());
    subLayout->addRow(new QLabel(tr("Downloadable items' paths")));
    subLayout->addRow(tr("Real path:"), absolutePathToDownloadableFilesLineEdit);
    subLayout->addRow(tr("Relative path"), relativePathToDownloadableFilesLineEdit);
    subLayout->addRow(createSpacingLayout());
    subLayout->addRow(new QLabel(tr("Pictures' paths")));
    subLayout->addRow(tr("Real path:"), absolutePathToPicturesLineEdit);
    subLayout->addRow(tr("Relative path"), relativePathToPicturesLineEdit);
    subLayout->addRow(createSpacingLayout());

    downloadListSettingsDialogButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok |
                                                               QDialogButtonBox::Cancel);
    //downloadListSettingsDialogButtonBox->setProperty("dialogbuttonbox-buttons-have-icons",true);
    downloadListSettingsDialogButtonBox->button(QDialogButtonBox::Ok)
                                       ->setIcon(QIcon(":/icons/apply.png"));
    downloadListSettingsDialogButtonBox->button(QDialogButtonBox::Cancel)
                                       ->setIcon(QIcon(":/icons/cancel.png"));

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(subLayout);
    mainLayout->addWidget(downloadListSettingsDialogButtonBox);

    setLayout(mainLayout);
}

QVBoxLayout *DownloadListSettingsDialog::createSpacingLayout()
{
    QVBoxLayout *spacingLayout = new QVBoxLayout();
    spacingLayout->addSpacing(10);

    return spacingLayout;
}
