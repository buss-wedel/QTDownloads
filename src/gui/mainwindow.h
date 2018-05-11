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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QToolBar>
#include <QTreeView>

#include "../core/aboutdata.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void aboutSlot();
    void configureFileSlot();
    void deleteCategorySlot();
    void deleteItemSlot();
    void editCategorySlot();
    void editItemSlot();
    void loadFileSlot();
    void newCategorySlot();
    void newItemSlot();
    void newFileSlot();
    void saveFileSlot();
    void saveFileAsSlot();
    void updateStatusBarSlot();

private:
    void createAboutData();
    void createActions();
    void createCentralWidget();
    void createConnections();
    void createContextMenu();
    void createMenus();
    void createStatusBar();
    void createToolBars();
    void setFileRelatedActionsAvailable(bool enable = false);

    QAction *newFileAction;
    QAction *openFileAction;
    QAction *saveFileAction;
    QAction *saveAsFileAction;
    QAction *exitAction;
    QAction *configureFileAction;
    QAction *newCategoryAction;
    QAction *editCategoryAction;
    QAction *deleteCategoryAction;
    QAction *newItemAction;
    QAction *editItemAction;
    QAction *deleteItemAction;
    QAction *aboutAction;
    QAction *aboutQtAction;

    QMenu *fileMenu;
    QMenu *categoryMenu;
    QMenu *itemMenu;
    QMenu *helpMenu;

    QToolBar *mainToolBar;

    QTreeView *mainTreeView;

    QLabel *statusLabel;

    AboutData *m_aboutData;
};

#endif // MAINWINDOW_H
