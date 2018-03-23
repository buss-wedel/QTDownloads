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
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();
}

MainWindow::~MainWindow()
{

}

void MainWindow::updateStatusBar()
{
    statusLabel->setText("dummy");
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
    exitAction->setStatusTip(tr("Exit this application"));

    newCategoryAction = new QAction(tr("&New category"), this);
    newCategoryAction->setStatusTip(tr("Create a new category"));

    editCategoryAction = new QAction(tr("&Edit category"), this);
    editCategoryAction->setStatusTip(tr("Edit an existing category"));

    deleteCategoryAction = new QAction(tr("&Delete category"), this);
    deleteCategoryAction->setStatusTip(tr("Deleten an existing category"));

    newItemAction = new QAction(tr("&New Item"), this);
    newItemAction->setStatusTip(tr("Create a new item"));

    editItemAction = new QAction(tr("&Edit item"), this);
    editItemAction->setStatusTip(tr("Edit an existing item"));

    deleteItemAction = new QAction(tr("&Delete item"), this);
    deleteItemAction->setStatusTip(tr("Delete an existing item"));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(saveFileAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit data"));
    editMenu->addAction(newCategoryAction);
    editMenu->addAction(editCategoryAction);
    editMenu->addAction(deleteCategoryAction);
    editMenu->addSeparator();
    editMenu->addAction(newItemAction);
    editMenu->addAction(editItemAction);
    editMenu->addAction(deleteItemAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));

}

void MainWindow::createContextMenu()
{
    //dummy - maybe for later usage
}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newFileAction);
    fileToolBar->addAction(openFileAction);
    fileToolBar->addAction(saveFileAction);
}

void MainWindow::createStatusBar()
{
    statusLabel = new QLabel("dummy");

    statusBar()->addWidget(statusLabel);

    updateStatusBar();
}
