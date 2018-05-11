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
