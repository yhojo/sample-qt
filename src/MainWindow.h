#ifndef __MAIN_WINDOW_H
#define __MAIN_WINDOW_H

#include <QWidget>

namespace UI {
  class MainWindow : public QWidget {
    Q_OBJECT
  public:
    MainWindow(QWidget *parent, QSize size);
    virtual ~MainWindow();
  };
}

#endif // __MAIN_WINDOW_H
