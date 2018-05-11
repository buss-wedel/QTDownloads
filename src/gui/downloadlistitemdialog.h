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
#ifndef DOWNLOADLISTITEMDIALOG_H
#define DOWNLOADLISTITEMDIALOG_H

#include "downloadlistcategorydialog.h"
#include "../3rdparty/wwwidgets/qwwfilechooser/qwwfilechooser.h"

#include <QCheckBox>
#include <QComboBox>

class DownloadListItemDialog : public DownloadListCategoryDialog
{
public:
    DownloadListItemDialog();

    QString absoluteFileName() const;
    QString absolutePictureName() const;
    QString groupName() const;
    QString relativeFileName() const;
    QString relativePictureName() const;
    Qt::CheckState useRelativeFileName() const;
    Qt::CheckState useRelativePictureName() const;

    void setData(const QString &name, const QString &description,
                 const QString &absoluteFileName, const Qt::CheckState useRelativeFileName,
                 const QString &relativeFileName, const QString &absolutePictureName,
                 const Qt::CheckState useRelativePictureName, const QString &relativePictureName,
                 const QString &groupName);

    void setAvailableGroups(const QStringList &groupList);

    void setGeneralPaths(const QString &absoluteGeneralFileDirectory,
                         const QString &relativeGeneralFileDirectory,
                         const QString &absoluteGeneralPictureDirectory,
                         const QString &relativeGeneralPictureDirectory);

private:
    void createDownloadListItemDialogLayout();
    void createConnections();

    QwwFileChooser *absoluteItemFileNameLineEdit;
    QCheckBox *useRelativeItemFileNameCheckBox;
    QLineEdit *relativeItemFileNameLineEdit;

    QwwFileChooser *absoluteItemPictureNameLineEdit;
    QCheckBox *useRelativeItemPictureNameCheckBox;
    QLineEdit *relativeItemPictureNameLineEdit;

    QComboBox *groupMembershipComboBox;

    QString _absoluteGeneralFileDirectory;
    QString _relativeGeneralFileDirectory;
    QString _absoluteGeneralPictureDirectory;
    QString _relativeGeneralPictureDirectory;
};

#endif // DOWNLOADLISTITEMDIALOG_H
