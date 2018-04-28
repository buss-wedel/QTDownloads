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

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createContextMenu();
    createMenus();
    createStatusBar();
    createToolBars();
}

MainWindow::~MainWindow()
{

}

void MainWindow::updateStatusBar()
{
    statusLabel->setText(QString("v%1").arg(APPLICATION_VERSION));
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
    deleteCategoryAction->setStatusTip(tr("Deleten an existing category"));

    newItemAction = new QAction(tr("&New Item"), this);
    newItemAction->setIcon(QIcon(":/icons/htmlnew.png"));
    newItemAction->setStatusTip(tr("Create a new item"));

    editItemAction = new QAction(tr("&Edit item"), this);
    editItemAction->setIcon(QIcon(":/icons/htmledit.png"));
    editItemAction->setStatusTip(tr("Edit an existing item"));

    deleteItemAction = new QAction(tr("&Delete item"), this);
    deleteItemAction->setIcon(QIcon(":/icons/htmlremove.png"));
    deleteItemAction->setStatusTip(tr("Delete an existing item"));
}

void MainWindow::createConnections()
{
    //placeholder - to be filled later
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

}

void MainWindow::createStatusBar()
{
    statusLabel = new QLabel("dummy");

    statusBar()->addWidget(statusLabel);

    updateStatusBar();
}

void MainWindow::createToolBars()
{
    mainToolBar = addToolBar(tr("&Main"));
    mainToolBar->addAction(newFileAction);
    mainToolBar->addAction(openFileAction);
    mainToolBar->addAction(saveFileAction);
    mainToolBar->addSeparator();
    mainToolBar->addAction(newCategoryAction);
    mainToolBar->addAction(editCategoryAction);
    mainToolBar->addAction(deleteCategoryAction);
    mainToolBar->addSeparator();
    mainToolBar->addAction(newItemAction);
    mainToolBar->addAction(editItemAction);
    mainToolBar->addAction(deleteItemAction);
}
