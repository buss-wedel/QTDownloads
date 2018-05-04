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
#include <QtWidgets>

#include "aboutdialog.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createAboutData();
    createActions();
    createConnections();
    createContextMenu();
    createMenus();
    createStatusBar();
    createToolBars();
    setFileRelatedActionsAvailable();
}

MainWindow::~MainWindow()
{

}

void MainWindow::aboutSlot()
{
    AboutDialog *dlg = new AboutDialog(m_aboutData);
    dlg->exec();
}

void MainWindow::loadFileSlot()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open download list data file"),
                                                    "",
                                                    tr("Download list data files (*.xml)"));

    if (!fileName.isEmpty()) {
        // try to load file
        setFileRelatedActionsAvailable(true);
    }
}

void MainWindow::deleteCategorySlot()
{

}

void MainWindow::deleteItemSlot()
{

}

void MainWindow::editCategorySlot()
{

}

void MainWindow::editItemSlot()
{

}

void MainWindow::newCategorySlot()
{

}

void MainWindow::newItemSlot()
{

}

void MainWindow::newFileSlot()
{
    // create new data object
    setFileRelatedActionsAvailable(true);
}

void MainWindow::saveFileSlot()
{
    // try to save current file
}

void MainWindow::saveFileAsSlot()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save download list data file"),
                                                    "",
                                                    tr("Download list data files (*.xml)"));
    if (!fileName.isEmpty()) {
        // give fileName to project and try to save it
    }
}

void MainWindow::updateStatusBarSlot()
{
    statusLabel->setText(QString("v%1").arg(APPLICATION_VERSION));
}

void MainWindow::createAboutData()
{
    m_aboutData = new AboutData( QCoreApplication::applicationName(),
                                 QCoreApplication::applicationVersion(),
                                 tr("A tool to manage and publish lists of downloadable items."),
                                 "Copyright 2018 Buss-Wedel &lt;buss-wedel@mail.com&gt;.",
                                 "Licensed under GNU GPL v3",
                                 QCoreApplication::organizationDomain());

    m_aboutData->addAuthor("Kjelt Hansen",
                           "",
                           "buss-wedel@mail.com");
    m_aboutData->addAuthor("Marie Hansen",
                           "",
                           "buss-wedel@mail.com");
    m_aboutData->addAuthor("Mark Buß",
                           tr("Author current and previous version of QTDownloads"),
                           "buss-wedel@mail.com");
    m_aboutData->addAuthor("Boris Müller-Rowold",
                           tr("Author of previous version of QTDownloads"));

    m_aboutData->setApplicationLicenseFile(QCoreApplication::applicationDirPath()+"/COPYING");
}

void MainWindow::createActions()
{
    newFileAction = new QAction(tr("&New"), this);
    newFileAction->setShortcut(QKeySequence::New);
    newFileAction->setIcon(QIcon(":/icons/filenew.png"));
    newFileAction->setStatusTip(tr("Create a new file"));

    openFileAction = new QAction(tr("&Open"), this);
    openFileAction->setShortcut(QKeySequence::Open);
    openFileAction->setIcon(QIcon(":/icons/fileopen.png"));
    openFileAction->setStatusTip(tr("Open an existing file"));

    saveFileAction = new QAction(tr("&Save"), this);
    saveFileAction->setShortcut(QKeySequence::Save);
    saveFileAction->setIcon(QIcon(":/icons/filesave.png"));
    saveFileAction->setStatusTip(tr("Save the document to disk"));

    saveAsFileAction = new QAction(tr("Save &As..."), this);
    saveAsFileAction->setShortcut(QKeySequence::SaveAs);
    saveAsFileAction->setIcon(QIcon(":/icons/filesaveas.png"));
    saveAsFileAction->setStatusTip(tr("Name and save the document to disk"));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setIcon(QIcon(":/icons/exit.png"));
    exitAction->setStatusTip(tr("Exit this application"));

    newCategoryAction = new QAction(tr("&New category"), this);
    newCategoryAction->setIcon(QIcon(":/icons/folder_html_new.png"));
    newCategoryAction->setStatusTip(tr("Create a new category"));

    editCategoryAction = new QAction(tr("&Edit category"), this);
    editCategoryAction->setIcon(QIcon(":/icons/folder_html_edit.png"));
    editCategoryAction->setStatusTip(tr("Edit an existing category"));

    deleteCategoryAction = new QAction(tr("&Delete category"), this);
    deleteCategoryAction->setIcon(QIcon(":/icons/folder_html_remove.png"));
    deleteCategoryAction->setStatusTip(tr("Delete an existing category"));

    newItemAction = new QAction(tr("&New Item"), this);
    newItemAction->setIcon(QIcon(":/icons/htmlnew.png"));
    newItemAction->setStatusTip(tr("Create a new item"));

    editItemAction = new QAction(tr("&Edit item"), this);
    editItemAction->setIcon(QIcon(":/icons/htmledit.png"));
    editItemAction->setStatusTip(tr("Edit an existing item"));

    deleteItemAction = new QAction(tr("&Delete item"), this);
    deleteItemAction->setIcon(QIcon(":/icons/htmlremove.png"));
    deleteItemAction->setStatusTip(tr("Delete an existing item"));

    configureFileAction = new QAction(tr("&File settings..."), this);
    configureFileAction->setIcon(QIcon(":/icons/configurefile.png"));
    configureFileAction->setStatusTip(tr("Allows modifying current file's settings."));

    aboutAction = new QAction(tr("&About QtDownloads"), this);
    aboutAction->setIcon(QIcon(":/icons/info.png"));
    aboutAction->setStatusTip(tr("Information about QtDownloads"));

    aboutQtAction = new QAction(tr("&About Qt"), this);
    aboutQtAction->setIcon(QIcon(":/icons/qt_logo_green_16x16px.png"));
    aboutQtAction->setStatusTip(tr("Information about Qt"));
}

void MainWindow::createCentralWidget()
{
    mainTreeView = new QTreeView();
    // Model has to been set later because it is not available at app start
    setCentralWidget(mainTreeView);
}

void MainWindow::createConnections()
{
    connect(newFileAction, &QAction::triggered, this, &MainWindow::newFileSlot);
    connect(openFileAction, &QAction::triggered, this, &MainWindow::loadFileSlot);
    connect(saveFileAction, &QAction::triggered, this, &MainWindow::saveFileSlot);
    connect(saveAsFileAction, &QAction::triggered, this, &MainWindow::saveFileAsSlot);
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);

    connect(aboutAction, &QAction::triggered,this, &MainWindow::aboutSlot);
    connect(aboutQtAction, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::createContextMenu()
{
    //dummy - maybe for later usage
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(saveFileAction);
    fileMenu->addAction(saveAsFileAction);
    fileMenu->addSeparator();
    fileMenu->addAction(configureFileAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    categoryMenu = menuBar()->addMenu(tr("&Category"));
    categoryMenu->addAction(newCategoryAction);
    categoryMenu->addAction(editCategoryAction);
    categoryMenu->addAction(deleteCategoryAction);

    itemMenu = menuBar()->addMenu(tr("&Item"));
    itemMenu->addAction(newItemAction);
    itemMenu->addAction(editItemAction);
    itemMenu->addAction(deleteItemAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutQtAction);
    helpMenu->addAction(aboutAction);
}

void MainWindow::createStatusBar()
{
    statusLabel = new QLabel("dummy");

    statusBar()->addPermanentWidget(statusLabel);

    updateStatusBarSlot();
}

void MainWindow::createToolBars()
{
    mainToolBar = addToolBar(tr("&Main toolbar"));
    mainToolBar->addAction(newFileAction);
    mainToolBar->addAction(openFileAction);
    mainToolBar->addAction(saveFileAction);
    mainToolBar->addAction(saveAsFileAction);
    mainToolBar->addSeparator();
    mainToolBar->addAction(configureFileAction);
    mainToolBar->addSeparator();
    mainToolBar->addAction(newCategoryAction);
    mainToolBar->addAction(editCategoryAction);
    mainToolBar->addAction(deleteCategoryAction);
    mainToolBar->addSeparator();
    mainToolBar->addAction(newItemAction);
    mainToolBar->addAction(editItemAction);
    mainToolBar->addAction(deleteItemAction);
}

void MainWindow::setFileRelatedActionsAvailable(bool enable)
{
    saveFileAction->setEnabled(enable);
    saveAsFileAction->setEnabled(enable);
    configureFileAction->setEnabled(enable);

    newCategoryAction->setEnabled(enable);
    editCategoryAction->setEnabled(enable);
    deleteCategoryAction->setEnabled(enable);

    newItemAction->setEnabled(enable);
    editItemAction->setEnabled(enable);
    deleteItemAction->setEnabled(enable);
}

