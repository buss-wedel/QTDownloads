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
#ifndef ABOUTDATA_H
#define ABOUTDATA_H

#include <QString>
#include <QVector>

class AboutData
{
public:
    AboutData(const QString &appName, const QString &appVersion,
              const QString &appDescription, const QString &appCopyright,
              const QString &appLicense, const QString &appHomepage);
    void addAuthor(const QString &name, const QString &task="",
                   const QString &email="", const QString &weblink="");
    void setApplicationLicenseFile(const QString &fileName);

    QString applicationName();
    QString applicationVersion();
    QString applicationDescription();
    QString applicationCopyright();
    QString applicationLicense();
    QString applicationHomepage();
    QString applicationLicenseFile();

    struct AboutDataEntry
    {
       AboutDataEntry(const QString &name, const QString &task,
                      const QString &email, const QString &weblink)
       : m_name(name), m_task(task), m_email(email), m_weblink(weblink)
       {}
       AboutDataEntry() {} //only to avoid a compile error
       QString m_name;
       QString m_task;
       QString m_email;
       QString m_weblink;
    };

    QVector<AboutDataEntry> authorList() const
    {
        return m_authorList;
    }

private:
    QVector<AboutDataEntry> m_authorList;

    QString m_ApplicationName;
    QString m_ApplicationVersion;
    QString m_ApplicationDescription;
    QString m_ApplicationCopyright;
    QString m_ApplicationLicense;
    QString m_ApplicationHomepage;
    QString m_ApplicationLicenseFile;
};

#endif // ABOUTDATA_H
