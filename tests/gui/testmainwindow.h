#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QObject>
#include <QtTest>

class TestMainWindow : public QObject
{
    Q_OBJECT

private slots:
    void testStubFail();
    void testStubPass();
};

#endif // TESTMAINWINDOW_H
