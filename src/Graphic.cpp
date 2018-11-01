

#include "../inc/Graphic.hpp"
#include "../inc/Userinfo.hpp"
#include "../inc/Time.hpp"
#include "../inc/OSinfo.hpp"
#include "../inc/RAM.hpp"
#include "../inc/Network.hpp"
#include "../inc/Unicorn.hpp"

Graphic::Graphic() {
  _xWin = 48;
  _yWin = 49;
  _x = 1;
  _y = 1;
}

Graphic::~Graphic() {
    endwin();
}

Graphic::Graphic(Graphic const & a) {
  *this = a;
}

Graphic& Graphic::operator=(Graphic const & a) {
  if (this != &a) {
    _user = a._user;
    _time = a._time;
    _os = a._os;
    _cpu = a._cpu;
    _ram = a._ram;
    _network = a._network;
    _pros = a._pros;
    _load = a._load;
    _yMax = a._yMax;
    _xMax = a._xMax;
    _xWin = a._xWin;
    _yWin = a._yWin;
    _x = a._x;
    _y = a._y;
    _winfo = a._winfo;
    _unicorn = a._unicorn;
  }
	return *this;
}

void  Graphic::makeBackground(WINDOW * _winfo, int y1, int y2) {
    while (y1 <= y2) {
      for (int x = 1; x < (_xWin - 1); x++)
        mvwprintw(_winfo, y1, x, " ");
      y1++;
    }
}

int   Graphic::chooseColor(int count) {
  if (count <= 8)
    return 3;
  else if (count <= 16)
    return 4;
  else
    return 5;
}

void  Graphic::CPUgraph(WINDOW * _winfo, int y) {

  mvwprintw(_winfo, y, 1,"User (%0.2f%%):", _cpu.getActUser());
  mvwprintw(_winfo, y + 1, 1,"Sys (%0.2f%%):", _cpu.getActSys());
  mvwprintw(_winfo, y + 2, 1,"Idle (%0.2f%%):", _cpu.getActIdle());
  int count = _cpu.getActUser() / 4;
  int x = 16;
  int color = chooseColor(count);

  wattron(_winfo, COLOR_PAIR(color));
  for (int i = 0; i < count; i++)
    mvwprintw(_winfo, y, x + i,"|");
  wattroff(_winfo, COLOR_PAIR(color));
  count = _cpu.getActSys() / 4;
  color = chooseColor(count);
  wattron(_winfo, COLOR_PAIR(color));
  for (int j = 0; j < count; j++)
    mvwprintw(_winfo, y + 1, x + j,"|");
  wattroff(_winfo, COLOR_PAIR(color));
  count = _cpu.getActIdle() / 4;
  color = chooseColor(count);
  wattron(_winfo, COLOR_PAIR(color));
  for (int z = 0; z < count; z++)
    mvwprintw(_winfo, y + 2, x + z,"|");
  wattroff(_winfo, COLOR_PAIR(color));
}

void  Graphic::RAMgraph(WINDOW * _winfo, int y) {
  int i = 0;
  int j = 0;
  int z = 0;
  mvwprintw(_winfo, y, 1,"Used:");
  mvwprintw(_winfo, y + 1, 1,"Wired:");
  mvwprintw(_winfo, y + 2, 1,"Unused:");
  double count =  _ram.getUsedMB() / 10;
  int x = 10;
  wattron(_winfo, COLOR_PAIR(4));
  mvwprintw(_winfo, y, x,"[");
  while (i < count) {
    i++;
    mvwprintw(_winfo, y, x + i,"/");
  }
  mvwprintw(_winfo, y, x + (++i),"]");
  mvwprintw(_winfo, y, x + (++i)," %0.2f%%", _ram.getUsedMB());
  wattroff(_winfo, COLOR_PAIR(4));
  wattron(_winfo, COLOR_PAIR(1));
   mvwprintw(_winfo, y, 38,"%lli%c", _ram.getUsedMem(), _ram.getUsedSize());
   wattroff(_winfo, COLOR_PAIR(1));

  count =  _ram.getWiredMB() / 10;
  wattron(_winfo, COLOR_PAIR(7));
  mvwprintw(_winfo, y + 1, x,"[");
  while (z < count) {
    z++;
    mvwprintw(_winfo, y + 1, x + z,"/");
  }
  mvwprintw(_winfo, y + 1, x + (++z),"]");
  mvwprintw(_winfo, y + 1, x + (++z)," %0.2f%%", _ram.getWiredMB());
  wattroff(_winfo, COLOR_PAIR(7));
  wattron(_winfo, COLOR_PAIR(1));
   mvwprintw(_winfo, y + 1, 38,"%lli%c", _ram.getWiredMem(), _ram.getWiredSize());
   wattroff(_winfo, COLOR_PAIR(1));

  count =  _ram.getUnusedMB() / 10;
  wattron(_winfo, COLOR_PAIR(6));
  mvwprintw(_winfo, y + 2, x,"[");
  while (j < count) {
    j++;
    mvwprintw(_winfo, y + 2, x + j,"/");
  }
  mvwprintw(_winfo, y + 2, x + (++j),"]");
  mvwprintw(_winfo, y + 2, x + (++j)," %0.2f%%", _ram.getUnusedMB());
  wattroff(_winfo, COLOR_PAIR(6));
  wattron(_winfo, COLOR_PAIR(1));
   mvwprintw(_winfo, y + 2, 38,"%lli%c", _ram.getUnusedMem(), _ram.getUnusedSize());
   wattroff(_winfo, COLOR_PAIR(1));
}

void Graphic::UserInfoDisplay() {
  wattron(_winfo, COLOR_PAIR(2));
  makeBackground(_winfo, _user.getStart(), _user.getStart());
  mvwprintw(_winfo, _user.getStart(), _xWin * 0.37, "User info");
  wattroff(_winfo, COLOR_PAIR(2));
  wattron(_winfo, COLOR_PAIR(1));
  makeBackground(_winfo, _user.getStart() + 1, _user.getStart() + 2);
  mvwprintw(_winfo, _user.getStart() + 1, 1, "HostName");
  mvwprintw(_winfo, _user.getStart() + 2, 1, "UserName");
    mvwprintw(_winfo, _user.getStart() + 1, 10, _user.getHostName());
    mvwprintw(_winfo, _user.getStart() + 2, 10, _user.getUserName());
    wattroff(_winfo, COLOR_PAIR(1));
}

void Graphic::DateTimeDisplay() {
 wattron(_winfo, COLOR_PAIR(2));
    makeBackground(_winfo, _time.getStart(), _time.getStart());
      mvwprintw(_winfo, _time.getStart(), _xWin * 0.35, "Date & Time");
      wattroff(_winfo, COLOR_PAIR(2));
      wattron(_winfo, COLOR_PAIR(1));
      makeBackground(_winfo, _time.getStart() + 1, _time.getStart() + 1);    
      mvwprintw(_winfo, _time.getStart() + 1, 20, "|");
    mvwprintw(_winfo, _time.getStart() + 1, 1, "Date:");
  mvwprintw(_winfo, _time.getStart() + 1, 22, "Time:");
    mvwprintw(_winfo, _time.getStart() + 1, 7, "%i.%i.%i", _time.getDateTime()->tm_mday, _time.getDateTime()->tm_mon + 1,\
      _time.getDateTime()->tm_year + 1900);
    mvwprintw(_winfo, _time.getStart() + 1, 28, "%i:%i:%i", _time.getDateTime()->tm_hour, _time.getDateTime()->tm_min,\
      _time.getDateTime()->tm_sec);
    wattroff(_winfo, COLOR_PAIR(1));
}

void Graphic::OSinfoDisplay() {
 wattron(_winfo, COLOR_PAIR(2));
    makeBackground(_winfo, _os.getStart(), _os.getStart());
    mvwprintw(_winfo, _os.getStart(), _xWin * 0.39, "OS info");
    wattroff(_winfo, COLOR_PAIR(2));
    wattron(_winfo, COLOR_PAIR(1));
    makeBackground(_winfo, _os.getStart() + 1, _os.getStart() + 5);
    mvwprintw(_winfo, _os.getStart() + 1, 1, "System Version: %s", _os.getVersion());
    mvwprintw(_winfo, _os.getStart() + 1, 38, "         ");
    mvwprintw(_winfo, _os.getStart() + 2, 1, "Kernel Version: %s", _os.getKernel());
    mvwprintw(_winfo, _os.getStart() + 2, 30, "                       ");
    mvwprintw(_winfo, _os.getStart() + 3, 1, "Boot Volume: %s", _os.getBootVol());
    mvwprintw(_winfo, _os.getStart() + 3, 20, "                            ");
    mvwprintw(_winfo, _os.getStart() + 4, 1, "Boot Mode: %s", _os.getBootMode());
    mvwprintw(_winfo, _os.getStart() + 4, 18, "                                 ");
    mvwprintw(_winfo, _os.getStart() + 5, 1, "Secure Virtual Memory: %s", _os.getSecureVirtMem());
    mvwprintw(_winfo, _os.getStart() + 5, 31, "                       ");
    mvwprintw(_winfo, _os.getStart() + 6, 1, "System Integrity Protection: %s", _os.getSystemIntegr());
    mvwprintw(_winfo, _os.getStart() + 6, 38, "                   ");
    mvwprintw(_winfo, _os.getStart() + 7, 1, "Time since boot: %s", _os.getTimeSinceBoot());
    mvwprintw(_winfo, _os.getStart() + 7, 23, "                         ");
    wattroff(_winfo, COLOR_PAIR(1));
    box(_winfo, 0, 0);
}

void Graphic::CPUdisplay() {
 wattron(_winfo, COLOR_PAIR(2));
    makeBackground(_winfo, _cpu.getStart(), _cpu.getStart());
    mvwprintw(_winfo, _cpu.getStart(), _xWin * 0.47, "CPU");
    wattroff(_winfo, COLOR_PAIR(2));
    wattron(_winfo, COLOR_PAIR(1));
    makeBackground(_winfo, _cpu.getStart() + 1, _cpu.getStart() + 5);
    CPUgraph(_winfo, _cpu.getStart() + 1);
    wattron(_winfo, COLOR_PAIR(1));
    mvwprintw(_winfo, _cpu.getStart() + 4, 1, "Model: %s", _cpu.getModel());
    mvwprintw(_winfo, _cpu.getStart() + 5, 1, "Speed: %0.2f GHz |",_cpu.getSpeed()); 
     mvwprintw(_winfo, _cpu.getStart() + 5, 19, " Cores: %i", _cpu.getCores());
    mvwprintw(_winfo, _cpu.getStart() + 5, 31, "| Processors: %i", _cpu.getCpus());
    wattroff(_winfo, COLOR_PAIR(1));
    box(_winfo, 0, 0);
}

void Graphic::RAMdisplay() {
 wattron(_winfo, COLOR_PAIR(2));
    makeBackground(_winfo, _ram.getStart(), _ram.getStart());
    mvwprintw(_winfo, _ram.getStart(), _xWin * 0.47, "RAM");
    wattroff(_winfo, COLOR_PAIR(2));
    wattron(_winfo, COLOR_PAIR(1));
    makeBackground(_winfo, _ram.getStart() + 1, _ram.getStart() + 3);
    RAMgraph(_winfo, _ram.getStart() + 1);
    wattroff(_winfo, COLOR_PAIR(1));
}

void Graphic::NetworkDisplay() {
     wattron(_winfo, COLOR_PAIR(2));
    makeBackground(_winfo, _network.getStart(), _network.getStart());
    mvwprintw(_winfo, _network.getStart(), _xWin * 0.39, "Network");
    wattroff(_winfo, COLOR_PAIR(2));
    wattron(_winfo, COLOR_PAIR(1));
    makeBackground(_winfo, _network.getStart() + 1, _network.getStart() + 2);
    mvwprintw(_winfo, _network.getStart() + 1, 1, "Packets In:               %lli/%lli%c", _network.getIn(),\
      _network.getInM(), _network.getInSize());
    mvwprintw(_winfo, _network.getStart() + 2, 1, "Packets Out:              %lli/%lli%c", _network.getOut(),\
      _network.getOutM(), _network.getOutSize());
    wattroff(_winfo, COLOR_PAIR(1));
}

void Graphic::ProcessDisplay() {
    wattron(_winfo, COLOR_PAIR(2));
    makeBackground(_winfo, _pros.getStart(), _pros.getStart());
    mvwprintw(_winfo, _pros.getStart(), _xWin * 0.38, "Processes");
    
    wattroff(_winfo, COLOR_PAIR(2));
    wattron(_winfo, COLOR_PAIR(7));
      makeBackground(_winfo, _pros.getStart() + 1, _pros.getStart() + 1);
    mvwprintw(_winfo, _pros.getStart() + 1, 1, "Total:        %i", _pros.getTotal());
    wattroff(_winfo, COLOR_PAIR(7));
    wattron(_winfo, COLOR_PAIR(1));
    mvwprintw(_winfo, _pros.getStart() + 1, 22, "|");
    wattron(_winfo, COLOR_PAIR(1));
    wattron(_winfo, COLOR_PAIR(3));
    mvwprintw(_winfo, _pros.getStart() + 1, 26, "Running:      %i", _pros.getRunning());
    wattroff(_winfo, COLOR_PAIR(3));
}

void Graphic::LoadAvgDisplay() {
    wattron(_winfo, COLOR_PAIR(2));
    makeBackground(_winfo, _load.getStart(), _load.getStart());
    mvwprintw(_winfo, _load.getStart(), _xWin * 0.39, "Load Avg");
    wattroff(_winfo, COLOR_PAIR(2));
     wattron(_winfo, COLOR_PAIR(1));
    makeBackground(_winfo, _load.getStart() + 1, _load.getStart() + 1);
   mvwprintw(_winfo, _load.getStart() + 1, 1, "   %0.2f           %0.2f           %0.2f", _load.getOneMin(), \
      _load.getFiveMin(), _load.getFifteenMin());
    wattroff(_winfo, COLOR_PAIR(1));
}

void  Graphic::displayMenu() {
  wattron(_winfo, COLOR_PAIR(2));
  makeBackground(_winfo, 40, 40);
  mvwprintw(_winfo, 40, _xWin * 0.45, "MENU");
  wattroff(_winfo, COLOR_PAIR(2));    
  wattron(_winfo, COLOR_PAIR(1));
   makeBackground(_winfo, 41, 47);
  mvwprintw(_winfo, 41, 1, "[1] - User info");
  mvwprintw(_winfo, 42, 1, "[2] - Time / Date");
  mvwprintw(_winfo, 43, 1, "[3] - OS info");
  mvwprintw(_winfo, 44, 1, "[4] - CPU");
  mvwprintw(_winfo, 45, 1, "[5] - RAM");
  mvwprintw(_winfo, 46, 1, "[6] - Network");
  mvwprintw(_winfo, 41, 24, "[7] - Processes");
  mvwprintw(_winfo, 42, 24, "[8] - Load Average");
  mvwprintw(_winfo, 43, 24, "[9] - Unicorn");
  mvwprintw(_winfo, 44, 24, "[b] - Blue Skin");
  mvwprintw(_winfo, 45, 24, "[r] - Red Skin");
  mvwprintw(_winfo, 46, 24, "[g] - Green Skin");
  mvwprintw(_winfo, 47, 1, "[q] - Quit");
  wattroff(_winfo, COLOR_PAIR(1));
}

void  Graphic::drawUnicorn() {
const char * uni1 = " \\";
const char * uni2 = " \\ji";
const char * uni3 = " /.((( ";
const char * uni4 = "(,/\"(((__,--.";
const char * uni5 = "    \\  ) _( /{ ";
const char * uni6 = "    !|| \" :||      ";
const char * uni7 = "    !||   :|| ";
const char * uni8 = "    \'\'\'   \'\'\' ";

    wattron(_winfo, COLOR_PAIR(2));
    makeBackground(_winfo, _unicorn.getStart(), _unicorn.getStart());
      mvwprintw(_winfo, _unicorn.getStart(), _xWin * 0.4, "Unicorn");
      wattroff(_winfo, COLOR_PAIR(2));
      wattron(_winfo, COLOR_PAIR(1));
      makeBackground(_winfo, _unicorn.getStart() + 1, _unicorn.getStart() + 8);
      int i = _unicorn.getUni();

    if (i == 0) {

      wattron(_winfo, COLOR_PAIR(6));
      mvwprintw(_winfo, _unicorn.getStart() + 1, 18, uni1);
      mvwprintw(_winfo, _unicorn.getStart() + 2, 18, uni2);
      mvwprintw(_winfo, _unicorn.getStart() + 3, 18, uni3);
      mvwprintw(_winfo, _unicorn.getStart() + 4, 18, uni4);
      wattroff(_winfo, COLOR_PAIR(6));
       wattron(_winfo, COLOR_PAIR(1));
       mvwprintw(_winfo, _unicorn.getStart() + 5, 18, uni5);
       mvwprintw(_winfo, _unicorn.getStart() + 6, 18, uni6);
       mvwprintw(_winfo, _unicorn.getStart() + 7, 18, uni7);
       mvwprintw(_winfo, _unicorn.getStart() + 8, 18, uni8);

        wattroff(_winfo, COLOR_PAIR(1));
        _unicorn.setUni(++i);
    }
    else if (i == 1) {
      wattron(_winfo, COLOR_PAIR(1));
      mvwprintw(_winfo, _unicorn.getStart() + 1, 18, uni1);
      mvwprintw(_winfo, _unicorn.getStart() + 2, 18, uni2);
      mvwprintw(_winfo, _unicorn.getStart() + 3, 18, uni3);
      mvwprintw(_winfo, _unicorn.getStart() + 4, 18, uni4);
      wattroff(_winfo, COLOR_PAIR(1));
       wattron(_winfo, COLOR_PAIR(6));
      mvwprintw(_winfo, _unicorn.getStart() + 5, 18, uni5);
       mvwprintw(_winfo, _unicorn.getStart() + 6, 18, uni6);
        wattroff(_winfo, COLOR_PAIR(6));
        wattron(_winfo, COLOR_PAIR(1));
      mvwprintw(_winfo, _unicorn.getStart() + 7, 18, uni7);
       mvwprintw(_winfo, _unicorn.getStart() + 8, 18, uni8);
       wattroff(_winfo, COLOR_PAIR(1));
        _unicorn.setUni(++i);
    }
    else if (i == 2) {
      wattron(_winfo, COLOR_PAIR(1));
      mvwprintw(_winfo, _unicorn.getStart() + 1, 18, uni1);
      mvwprintw(_winfo, _unicorn.getStart() + 2, 18, uni2);
      mvwprintw(_winfo, _unicorn.getStart() + 3, 18, uni3);
      mvwprintw(_winfo, _unicorn.getStart() + 4, 18, uni4);
      mvwprintw(_winfo, _unicorn.getStart() + 5, 18, uni5);
       mvwprintw(_winfo, _unicorn.getStart() + 6, 18, uni6);
      wattroff(_winfo, COLOR_PAIR(1));
       wattron(_winfo, COLOR_PAIR(6));
      mvwprintw(_winfo, _unicorn.getStart() + 7, 18, uni7);
       mvwprintw(_winfo, _unicorn.getStart() + 8, 18, uni8);
        wattroff(_winfo, COLOR_PAIR(1));
          _unicorn.setUni(0);
    }
}

void Graphic::displayAll() {
	initscr();
	cbreak();
	curs_set(0); 
  noecho();
	getmaxyx(stdscr, _yMax, _xMax);
	_winfo = newwin(_yWin, _xWin, 0, 0);
  keypad(stdscr, true);
  nodelay(stdscr, true);
  keypad(_winfo, true);
  nodelay(_winfo, true);
  start_color();
  init_color(COLOR_BLUE, 0, 71, 179);
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLUE, COLOR_WHITE);
    init_pair(3, COLOR_GREEN, COLOR_BLUE);
    init_pair(4, COLOR_YELLOW, COLOR_BLUE);
    init_pair(5, COLOR_RED, COLOR_BLUE);
    init_pair(6, COLOR_MAGENTA, COLOR_BLUE);
    init_pair(7, COLOR_CYAN, COLOR_BLUE);
    int choice = 0;
    box(_winfo, 0, 0);
    displayMenu();
      refresh();
  wrefresh(_winfo);

  while (1) {

     choice = getch();
    if (choice == '1' && _user.getShow() == 0) {
      _user.setStart(_y);
        UserInfoDisplay();
        _user.setShow(1);
        _y = _y + _user.getHeight();
    }
    else if (choice == '2' && _time.getShow() != 1) {
      _time.setStart(_y);
      DateTimeDisplay();
      _time.setShow(1);
      _y = _y + _time.getHeight();
    }
    else if (choice == '3' && _os.getShow() != 1) {
      _os.setStart(_y);
      OSinfoDisplay();
      _os.setShow(1);
      _y = _y + _os.getHeight();
    }
    else if (choice == '4' && _cpu.getShow() != 1) {
      _cpu.setStart(_y);
      CPUdisplay();
      _cpu.setShow(1);
      _y = _y + _cpu.getHeight();
    }
     else if (choice == '5' && _ram.getShow() != 1) {
      _ram.setStart(_y);
          RAMdisplay();
      _ram.setShow(1);
      _y = _y + _ram.getHeight();
    }
     else if (choice == '6' && _network.getShow() != 1) {
      _network.setStart(_y);
      NetworkDisplay();
      _network.setShow(1);
      _y = _y + _network.getHeight();
    }
     else if (choice == '7' && _pros.getShow() != 1) {
      _pros.setStart(_y);
      ProcessDisplay();
      _pros.setShow(1);
      _y = _y + _pros.getHeight();
    }
     else if (choice == '8' && _load.getShow() != 1) {
      _load.setStart(_y);
      LoadAvgDisplay();
      _load.setShow(1);
      _y = _y + _load.getHeight();
    }
    else if (choice == '9' && _unicorn.getShow() != 1) {
      _unicorn.setStart(_y);
      drawUnicorn();
      _unicorn.setShow(1);
      _y = _y + _unicorn.getHeight();
    }
    else if (choice == 'g')
      init_color(COLOR_BLUE, 0, 77, 0);
    else if (choice == 'b')
      init_color(COLOR_BLUE, 0, 71, 179);
    else if (choice == 'r')
      init_color(COLOR_BLUE, 102, 0, 0);
    else if (choice == 'q') {
      break ;
    }
     if(_time.getShow() == 1) {
        _time.reload();
        DateTimeDisplay();
     }
    if (_user.getShow() == 1) {
      _user.reload();
       UserInfoDisplay();
    }
      if (_os.getShow() == 1) {
        _os.reload();
        OSinfoDisplay();
      }
      if (_cpu.getShow() == 1) {
        _cpu.reload();
        CPUdisplay();
      }
      if (_ram.getShow() == 1) {
        _ram.reload();
        RAMdisplay();
      }
      if (_network.getShow() == 1) {
        _network.reload();
        NetworkDisplay();
      }
      if (_pros.getShow() == 1) {
        _pros.reload();
        ProcessDisplay();
      }
      if (_load.getShow() == 1) {
        _load.reload();
        LoadAvgDisplay();
      }
      if(_unicorn.getShow() == 1) {
        _unicorn.reload();
        drawUnicorn();
      }
    
  	refresh();
  	wrefresh(_winfo);
  }
}
