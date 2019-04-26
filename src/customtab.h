#ifndef CUSTOMTAB_H
#define CUSTOMTAB_H

#include <QTabWidget>
#include <QTextBrowser>

class CustomTab : public QTabWidget
{
    Q_OBJECT
public:
    explicit CustomTab(QTabWidget *parent = nullptr);

signals:

public slots:


private:
    QTextBrowser *movesBrowser;
};

#endif // CUSTOMTAB_H
