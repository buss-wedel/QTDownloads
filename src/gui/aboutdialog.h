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
#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QLabel>
#include <QTabWidget>
#include <QTextBrowser>

#include "../core/aboutdata.h"

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    AboutDialog(AboutData *data);

private slots:
    void openLinkSlot(const QUrl &link);

private:
    void createAboutDialogLayout();
    void createAboutTab();
    void createAuthorTab();
    void createConnections();
    void createLicenseTab();

    QLabel *appLogo;
    QLabel *appNameAndVersion;

    QTabWidget *aboutTabWidget;
    QDialogButtonBox *aboutDialogButtonBox;

    QWidget *aboutPageWidget;
    QTextBrowser *aboutPageTextBrowser;

    QWidget *authorsPageWidget;
    QTextBrowser *authorsPageTextBrowser;

    QWidget *licensePageWidget;
    QTextBrowser *licensePageTextBrowser;

    AboutData *m_data;

};

#endif // ABOUTDIALOG_H
