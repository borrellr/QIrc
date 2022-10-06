#include "xIrcDefaults.h"

xIrcDefaults::xIrcDefaults()
{
}

xIrcDefaults::~xIrcDefaults()
{
}

void xIrcDefaults::loadData(QFile &f)
{
   QTextStream stream(&f);
   QString line, line2, key, value;
   bool dbg = false;
   int i = 0;

   while ( !stream.atEnd() ) {
      line = stream.readLine(); // line of text excluding '\n'
      if (!line.isEmpty()) {
         if (line.endsWith("\\")) {
            line2.append(line);
         } else {
            if (line2.isEmpty()) {
               line = line.simplifyWhiteSpace();
               key = line.section("=", 0, 0);
               value = line.section("=", 1, 1);
               dmap[key.upper()] = value.simplifyWhiteSpace();
               if (dbg) 
                  printf( "%3d: %s\n", i++, line.latin1() );
            } else {
               line2.remove("\\");
               line2 = line2.simplifyWhiteSpace();
               key = line2.section("=", 0, 0);
               value = line2.section("=", 1, 1);
               dmap[key.upper()] = value.simplifyWhiteSpace();
               if (dbg) 
                  printf( "%3d: %s\n", i++, line2.latin1() );
               line2 = "";
            }
         }
      }
   }
}

void xIrcDefaults::openDefaults(QString filename)
{
   QFile f(filename);

   if (f.exists()) {
      if (!f.open(IO_ReadOnly)) {
         qWarning("Missing file %s\n", filename.latin1());
         return;
      }
      loadData(f);
      f.close();
   } else {
      printf("File %s does not exists\n", filename.latin1());
   }
}

void xIrcDefaults::load()
{
   bool dbg = false;
   QString filename("/usr/local/lib/xIrc/xIrc.defaults");

   // Load global defaults
   if (dbg) 
      printf("filename is %s\n", filename.latin1());
   openDefaults(filename);

   // Load user defaults
   filename = getenv("HOME");
   filename.append("/.xIrc/xIrc.ini");
   openDefaults(filename);
}

void xIrcDefaults::show()
{
   defaultMap::Iterator it;

   printf("Printing Default keys and values:\n");
   for ( it = dmap.begin(); it != dmap.end(); ++it ) {
       printf("Key: \"%s\" Value: \"%s\"\n", it.key().latin1(), it.data().latin1());
   }
   printf("Printed Default keys and values:\n");
}

void xIrcDefaults::save()
{
   if (getChanged()) {
      QDir d(getenv("HOME"));
      QFile file(d.filePath(".xirc"));
      if (!file.open(IO_Truncate|IO_WriteOnly)) {
         qWarning("Missing local .xirc file");
         return;
      }
      QTextStream wstream(&file);
      defaultMap::Iterator it;
      for (it = dmap.begin(); it != dmap.end(); ++it) {
          QString data(it.key());
          data.append("=");
          data.append(it.data());
          printf("Data: %s\n", data.latin1());
          wstream << data.latin1() << '\n';
      }
      file.close();
   }
}

void xIrcDefaults::set(QString key, QString value)
{
    dmap.insert(key.upper(), value.simplifyWhiteSpace(), TRUE);
    setChanged();
}

QString xIrcDefaults::get(QString key)
{
   QString s("");
   key = key.upper();
   defaultMap::iterator it = dmap.find(key);

   if (it != dmap.end())
      s.append(it.data());

   return s;
}

bool xIrcDefaults::getChanged()
{
    return changed;
}

void xIrcDefaults::setChanged()
{
    changed = TRUE;
}
