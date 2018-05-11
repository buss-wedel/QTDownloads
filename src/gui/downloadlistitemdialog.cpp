#include "downloadlistitemdialog.h"

#include <QLabel>
#include <QDebug>

DownloadListItemDialog::DownloadListItemDialog()
{
    parent();
    createDownloadListItemDialogLayout();

    setWindowTitle(tr("Create a new item"));
}

QString DownloadListItemDialog::absoluteFileName() const
{
    return absoluteItemFileNameLineEdit->text();
}

QString DownloadListItemDialog::absolutePictureName() const
{
    return absoluteItemPictureNameLineEdit->text();
}

QString DownloadListItemDialog::groupName() const
{
    return groupMembershipComboBox->currentText();
}

QString DownloadListItemDialog::relativeFileName() const
{
    return relativeItemFileNameLineEdit->text();
}

QString DownloadListItemDialog::relativePictureName() const
{
    return relativeItemPictureNameLineEdit->text();
}

Qt::CheckState DownloadListItemDialog::useRelativeFileName() const
{
    return useRelativeItemFileNameCheckBox->checkState();
}

Qt::CheckState DownloadListItemDialog::useRelativePictureName() const
{
    return useRelativeItemPictureNameCheckBox->checkState();
}

void DownloadListItemDialog::setData(const QString &name, const QString &description, const QString &absoluteFileName, const Qt::CheckState useRelativeFileName, const QString &relativeFileName, const QString &absolutePictureName, const Qt::CheckState useRelativePictureName, const QString &relativePictureName, const QString &groupName)
{
    DownloadListCategoryDialog::setData(name,description);

    absoluteItemFileNameLineEdit->setText(absoluteFileName);
    useRelativeItemFileNameCheckBox->setCheckState(useRelativeFileName);
    relativeItemFileNameLineEdit->setText(relativeFileName);

    absoluteItemPictureNameLineEdit->setText(absolutePictureName);
    useRelativeItemPictureNameCheckBox->setCheckState(useRelativePictureName);
    relativeItemPictureNameLineEdit->setText(relativePictureName);

    groupMembershipComboBox->setCurrentText(groupName);

    setWindowTitle(tr("Edit an item"));
}

void DownloadListItemDialog::setAvailableGroups(const QStringList &groupList)
{
    groupMembershipComboBox->addItems(groupList);
}

void DownloadListItemDialog::setGeneralPaths(const QString &absoluteGeneralFileDirectory, const QString &relativeGeneralFileDirectory, const QString &absoluteGeneralPictureDirectory, const QString &relativeGeneralPictureDirectory)
{
    _absoluteGeneralFileDirectory = absoluteGeneralFileDirectory;
    _relativeGeneralFileDirectory = relativeGeneralFileDirectory;
    _absoluteGeneralPictureDirectory = absoluteGeneralPictureDirectory;
    _relativeGeneralPictureDirectory = relativeGeneralPictureDirectory;

    if (DownloadListCategoryDialog::name().isEmpty()) {
        absoluteItemFileNameLineEdit->setText(absoluteGeneralFileDirectory);
        absoluteItemPictureNameLineEdit->setText(absoluteGeneralPictureDirectory);
    }
}

void DownloadListItemDialog::createDownloadListItemDialogLayout()
{
    absoluteItemFileNameLineEdit = new QwwFileChooser();
    absoluteItemFileNameLineEdit->setIcon(QIcon(":/icons/fileopen.png"));

    useRelativeItemFileNameCheckBox = new QCheckBox(tr("Use relative path"));

    relativeItemFileNameLineEdit = new QLineEdit();

    subFormLayout()->addItem(createSpacingLayout());
    subFormLayout()->addRow(new QLabel(tr("Downloadable file information")));
    subFormLayout()->addRow(tr("Real path:"),absoluteItemFileNameLineEdit);
    subFormLayout()->addRow(tr(""), useRelativeItemFileNameCheckBox);
    subFormLayout()->addRow(tr("Relative path:"), relativeItemFileNameLineEdit);

    absoluteItemPictureNameLineEdit = new QwwFileChooser();
    absoluteItemPictureNameLineEdit->setIcon(QIcon(":/icons/fileopen.png"));

    useRelativeItemPictureNameCheckBox = new QCheckBox(tr("Use relative path"));

    relativeItemPictureNameLineEdit = new QLineEdit();

    subFormLayout()->addItem(createSpacingLayout());
    subFormLayout()->addRow(new QLabel(tr("Picture file information")));
    subFormLayout()->addRow(tr("Real path:"), absoluteItemPictureNameLineEdit);
    subFormLayout()->addRow(tr(""), useRelativeItemPictureNameCheckBox);
    subFormLayout()->addRow(tr("Relative path:"), relativeItemPictureNameLineEdit);

    groupMembershipComboBox = new QComboBox();

    subFormLayout()->addItem(createSpacingLayout());
    subFormLayout()->addRow(tr("Group membership:"), groupMembershipComboBox);
}

void DownloadListItemDialog::createConnections()
{
    parent();

}
