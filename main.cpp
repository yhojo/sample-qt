
#include <QApplication>
#include <QDesktopWidget>

#include "MainWindow.h"

const int LCD_DEFAULT_WIDTH = 1280;
const int LCD_DEFAULT_HEIGHT = 800;

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  auto window = new UI::MainWindow(nullptr, QSize(LCD_DEFAULT_WIDTH, LCD_DEFAULT_HEIGHT));
  auto geometry = QApplication::desktop()->screenGeometry(window);
  if (LCD_DEFAULT_WIDTH < geometry.width() && LCD_DEFAULT_HEIGHT < geometry.height()) {
    window->resize(LCD_DEFAULT_WIDTH, LCD_DEFAULT_HEIGHT);
  }
  window->show();

  return app.exec();
}
