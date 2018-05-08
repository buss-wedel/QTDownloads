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
#include <QDebug>
#include <QDesktopServices>
#include <QFile>
#include <QHBoxLayout>
#include <QTextBrowser>

#include "aboutdialog.h"

AboutDialog::AboutDialog(AboutData *data)
{
    m_data = data;
    createAboutDialogLayout();
    createAboutTab();
    createAuthorTab();
    createLicenseTab();
    createConnections();
    setWindowTitle(tr("About %1").arg(m_data->applicationName()));
}

void AboutDialog::openLinkSlot(const QUrl &link)
{
    QDesktopServices::openUrl(link);
}

void AboutDialog::createAboutDialogLayout()
{
    appLogo = new QLabel();
    appLogo->setPixmap(QPixmap(":/icons/favicon-16x16.png"));
    appNameAndVersion = new QLabel("<p><b><font size=\"5\">%1</font></b><br>Version %2</p>");
    appNameAndVersion->setText(appNameAndVersion->text()
                               .arg(m_data->applicationName())
                               .arg(m_data->applicationVersion()));

    QHBoxLayout *titleLayout = new QHBoxLayout();
    titleLayout->addWidget(appLogo);
    titleLayout->addWidget(appNameAndVersion);
    titleLayout->addStretch();

    aboutTabWidget = new QTabWidget();

    aboutDialogButtonBox = new QDialogButtonBox(QDialogButtonBox::Close);

    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->addLayout(titleLayout, 0, 0, Qt::AlignTop);
    mainLayout->addWidget(aboutTabWidget, 1, 0);
    mainLayout->addWidget(aboutDialogButtonBox, 2, 0);

    setLayout(mainLayout);
}

void AboutDialog::createAboutTab()
{
    QString textTemplate = "<p>%1<br></p><p>%2</p><p>%3<br></p><p><a href=\"%4\">%4</a></p>";

    aboutPageTextBrowser = new QTextBrowser();
    aboutPageTextBrowser->setOpenLinks(false);
    aboutPageTextBrowser->setText(textTemplate
                                  .arg(m_data->applicationDescription())
                                  .arg(m_data->applicationCopyright())
                                  .arg(m_data->applicationLicense())
                                  .arg(m_data->applicationHomepage()));

    QVBoxLayout *pageLayout = new QVBoxLayout();
    pageLayout->addWidget(aboutPageTextBrowser);

    aboutPageWidget = new QWidget();
    aboutPageWidget->setLayout(pageLayout);

    aboutTabWidget->addTab(aboutPageWidget, tr("&About"));
}

void AboutDialog::createAuthorTab()
{
    QString nameTemplate = "<b>%1</b>&nbsp;&nbsp;";
    QString taskTemplate = "<br>%2";
    QString emailTemplate = "&lt;%3&gt;";
    QString weblinkTemplate = "<br><a href=\"%4\">%4</a>";

    QString textTemplate = "<p>%10</p>";

    QString textToDisplay;  //for the content of the QTextBrowser

    for (int i = 0; i < m_data->authorList().size(); ++i) {
        QString tmp = nameTemplate.arg(m_data->authorList().at(i).m_name);
        if (!m_data->authorList().at(i).m_email.isEmpty()) {
            tmp.append(emailTemplate.arg(m_data->authorList().at(i).m_email));
        }
        if (!m_data->authorList().at(i).m_task.isEmpty()) {
            tmp.append(taskTemplate.arg(m_data->authorList().at(i).m_task));
        }
        if (!m_data->authorList().at(i).m_weblink.isEmpty()) {
            tmp.append(weblinkTemplate.arg(m_data->authorList().at(i).m_weblink));
        }
        if (!m_data->authorList().at(i).m_name.isEmpty()) {
            textToDisplay.append(textTemplate.arg(tmp));
        }
    }

    authorsPageTextBrowser = new QTextBrowser();
    authorsPageTextBrowser->setOpenLinks(false);
    authorsPageTextBrowser->setText(textToDisplay);

    QVBoxLayout *pageLayout = new QVBoxLayout();
    pageLayout->addWidget(authorsPageTextBrowser);

    authorsPageWidget = new QWidget();
    authorsPageWidget->setLayout(pageLayout);

    aboutTabWidget->addTab(authorsPageWidget, tr("A&uthors"));
}

void AboutDialog::createConnections()
{
    connect(aboutDialogButtonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    connect(aboutPageTextBrowser, &QTextBrowser::anchorClicked, this, &AboutDialog::openLinkSlot);
    connect(authorsPageTextBrowser, &QTextBrowser::anchorClicked, this, &AboutDialog::openLinkSlot);
    connect(licensePageTextBrowser, &QTextBrowser::anchorClicked, this, &AboutDialog::openLinkSlot);
}

void AboutDialog::createLicenseTab()
{
    QString licenseText;
    QFile file(m_data->applicationLicenseFile());
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            licenseText.append(in.readLine()).append("#br#");
        }
    }
    licenseText.replace("<", "&lt;");
    licenseText.replace(">", "&gt;");
    licenseText.replace("#br#", "<br>");

    licensePageTextBrowser = new QTextBrowser();
    licensePageTextBrowser->setOpenLinks(false);
    licensePageTextBrowser->setText(licenseText);

    QVBoxLayout *pageLayout = new QVBoxLayout();
    pageLayout->addWidget(licensePageTextBrowser);

    licensePageWidget = new QWidget();
    licensePageWidget->setLayout(pageLayout);

    aboutTabWidget->addTab(licensePageWidget, tr("&License"));
}
