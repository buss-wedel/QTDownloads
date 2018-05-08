#ifndef DOWNLOADLISTSETTINGSDIALOG_H
#define DOWNLOADLISTSETTINGSDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QVBoxLayout>

#include "../3rdparty/wwwidgets/qwwfilechooser/qwwfilechooser.h"

class DownloadListSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    DownloadListSettingsDialog();

    QString templateFileName() const;
    QString absoluteFilesPath() const;
    QString relativeFilesPath() const;
    QString absolutePicturePath() const;
    QString relativePicturePath() const;

    void setData(const QString &fileName, const QString &templateFileName,
                 const QString &absoluteFilesPath, const QString &relativeFilesPath,
                 const QString &absolutePicturePath, const QString &relativePicturePath);
private:
    void createConnections();
    void createDownloadListSettingsDialogLayout();
    QVBoxLayout *createSpacingLayout();

    QLineEdit *currentListFileNameLineEdit;
    QwwFileChooser *currentTemplateFileNameLineEdit;

    QwwFileChooser *absolutePathToDownloadableFilesLineEdit;
    QLineEdit *relativePathToDownloadableFilesLineEdit;

    QwwFileChooser *absolutePathToPicturesLineEdit;
    QLineEdit *relativePathToPicturesLineEdit;

    QDialogButtonBox *downloadListSettingsDialogButtonBox;
};

#endif // DOWNLOADLISTSETTINGSDIALOG_H
