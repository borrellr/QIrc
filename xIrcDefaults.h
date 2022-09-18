#ifndef XIRCDEFAULTS_H
#define XIRCDEFAULTS_H

#include <qdir.h>
#include <qfile.h>
#include <qmap.h>
#include <qstring.h>

typedef QMap<QString, QString> defaultMap;

class xIrcDefaults
{
public:
  xIrcDefaults();
  ~xIrcDefaults();
  void load();
  void show();
  void save();
  void setChanged();
  bool  getChanged();
  void set(QString key, QString value);
  QString get(QString key);

private:
  bool changed;
  defaultMap dmap;
};

#endif
