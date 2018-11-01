


#include "../inc/OSinfo.hpp"

OSinfo::OSinfo() {
  _show = 0;
  _height = 8;
  _start = 0;
  reload();
}

OSinfo::~OSinfo() {}

OSinfo::OSinfo(OSinfo const &a) {
	*this = a;
}

OSinfo& OSinfo::operator=(OSinfo const &a) {
	if (this != &a) {
    _show = a._show;
    _start = a._start;
    _height = a._height;
    _version = a._version;
    _kernel = a._kernel;
    _boot_vol = a._boot_vol;
    _boot_mode = a._boot_mode;
    _secure_virt_mem = a._secure_virt_mem;
    _system_integr = a._system_integr;
    _time_since_boot = a._time_since_boot;
  }
	return *this;
}

void  OSinfo::reload() {
  char buff[256];
  std::string s;

  FILE *version = popen("system_profiler SPSoftwareDataType | grep \"System Version:\"", "r");// -> Generate a text report containing only software data.
  if (!version)
    std::cout << "ERROR opening OSinfo file" << std::endl;  
  else {
      fgets(buff, sizeof(buff), version);
      pclose(version);
      s = static_cast<std::string>(buff);
      s = s.substr(22, 45);
       _version = s;
   }

  char buff1[256];
  std::string s1;
   FILE *kernel = popen("system_profiler SPSoftwareDataType | grep \"Kernel Version:\"", "r");// -> Generate a text report containing only software data.
  if (!kernel)
    std::cout << "ERROR opening OSinfo file" << std::endl;  
 else {
      fgets(buff1, sizeof(buff1), kernel);
      pclose(kernel);
      s1 = static_cast<std::string>(buff1);
      s1 = s1.substr(22, 37);
       _kernel = s1;
   }

  char buff2[256];
  std::string s2;
   FILE *boot_vol = popen("system_profiler SPSoftwareDataType | grep \"Boot Volume:\"", "r");// -> Generate a text report containing only software data.
  if (!boot_vol)
    std::cout << "ERROR opening OSinfo file" << std::endl;  
  else {
      fgets(buff2, sizeof(buff2), boot_vol);
      pclose(boot_vol);
      s2 = static_cast<std::string>(buff2);
      s2 = s2.substr(19, 24);
       _boot_vol = s2;
   }

  char buff3[256];
  std::string s3;
   FILE *boot_mode = popen("system_profiler SPSoftwareDataType | grep \"Boot Mode:\"", "r");// -> Generate a text report containing only software data.
  if (!boot_mode)
    std::cout << "ERROR opening OSinfo file" << std::endl;  
  else {
      fgets(buff3, sizeof(buff3), boot_mode);
      pclose(boot_mode);
      s3 = static_cast<std::string>(buff3);
      s3 = s3.substr(17, 22);
       _boot_mode = s3;
   }

  char buff4[256];
  std::string s4;
   FILE *virt_mem = popen("system_profiler SPSoftwareDataType | grep \"Secure Virtual Memory:\"", "r");// -> Generate a text report containing only software data.
  if (!virt_mem)
    std::cout << "ERROR opening OSinfo file" << std::endl;  
  else {
      fgets(buff4, sizeof(buff4), virt_mem);
      pclose(virt_mem);
      s4 = static_cast<std::string>(buff4);
      s4 = s4.substr(29, 38);
       _secure_virt_mem = s4;
   }

  char buff5[256];
  std::string s5;
   FILE *integrity_protect = popen("system_profiler SPSoftwareDataType | grep \"System Integrity Protection:\"", "r");// -> Generate a text report containing only software data.
  if (!integrity_protect)
    std::cout << "ERROR opening OSinfo file" << std::endl;  
  else {
      fgets(buff5, sizeof(buff5), integrity_protect);
      pclose(integrity_protect);
      s5 = static_cast<std::string>(buff5);
      s5 = s5.substr(35, 45);
       _system_integr = s5;
   }

  char buff6[256];
  std::string s6;
   FILE *time_boot = popen("system_profiler SPSoftwareDataType | grep \"Time since boot:\"", "r");// -> Generate a text report containing only software data.
  if (!time_boot)
    std::cout << "ERROR opening OSinfo file" << std::endl;  
  else {
      fgets(buff6, sizeof(buff6), time_boot);
      pclose(time_boot);
      s6 = static_cast<std::string>(buff6);
      s6 = s6.substr(23, 27);
       _time_since_boot = s6;
   }
}

int OSinfo::getHeight() {
  return _height;
}

const char * OSinfo::getVersion() {
  return _version.c_str();
}


const char * OSinfo::getKernel() {
  return _kernel.c_str();
}

const char * OSinfo::getBootVol() {
  return _boot_vol.c_str();
}

const char * OSinfo::getBootMode() {
  return _boot_mode.c_str();
}

const char * OSinfo::getSecureVirtMem() {
  return _secure_virt_mem.c_str();
}

const char * OSinfo::getSystemIntegr() {
  return _system_integr.c_str();
}

const char * OSinfo::getTimeSinceBoot() {
  return _time_since_boot.c_str();
}

int OSinfo::getShow() {
  return _show;
}
    
void OSinfo::setShow(int i) {
  _show = i;
}


int   OSinfo::getStart() {
  return _start;
}

void    OSinfo::setStart(int i) {
  _start = i;
}
