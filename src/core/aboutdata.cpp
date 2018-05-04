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
#include "aboutdata.h"


AboutData::AboutData(const QString &appName, const QString &appVersion, const QString &appDescription, const QString &appCopyright, const QString &appLicense, const QString &appHomepage)
{
    m_ApplicationName = appName;
    m_ApplicationVersion = appVersion;
    m_ApplicationDescription = appDescription;
    m_ApplicationCopyright = appCopyright;
    m_ApplicationLicense = appLicense;
    m_ApplicationHomepage = appHomepage;
}

void AboutData::addAuthor(const QString &name, const QString &task, const QString &email, const QString &weblink)
{
    m_authorList.append( AboutDataEntry( name, task, email, weblink) );
}

void AboutData::setApplicationLicenseFile(const QString &fileName)
{
    m_ApplicationLicenseFile = fileName;
}

QString AboutData::applicationCopyright()
{
    return m_ApplicationCopyright;
}

QString AboutData::applicationLicense()
{
    return m_ApplicationLicense;
}

QString AboutData::applicationHomepage()
{
    return m_ApplicationHomepage;
}

QString AboutData::applicationLicenseFile()
{
    return m_ApplicationLicenseFile;
}

QString AboutData::applicationDescription()
{
    return m_ApplicationDescription;
}

QString AboutData::applicationVersion()
{
    return m_ApplicationVersion;
}

QString AboutData::applicationName()
{
    return m_ApplicationName;
}

