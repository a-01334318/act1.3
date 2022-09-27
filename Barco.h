#ifndef BARCO_H
#define BARCO_H

#include <string>
using namespace std;

class Barco{
public:
  string date, hour, entry, UBI;
  Barco(string, string, string, string);
  bool operator>(Barco &);
  friend ostream &operator<<(ostream &os, const Barco &barco);
};

Barco::Barco(string dat, string hr, string ent, string U){
  date = dat;
  hour = hr;
  entry = ent;
  UBI = U;
};

bool Barco::operator>(Barco &other){
  if (stoi(date.substr(3, 2)) > stoi(other.date.substr(3, 2))){
    return true;
  }
  else if (stoi(date.substr(3, 2)) < stoi(other.date.substr(3, 2))){
    return false;
  }
  else{
    if (stoi(date.substr(0, 2)) > stoi(other.date.substr(0, 2))){
      return true;
    }
    else{
      return false;
    }
  }
}

ostream &operator<<(ostream &os, const Barco &barco){
  os << barco.date << " " << barco.hour << " " << barco.entry << " " << barco.UBI;
  return os;
}

#endif
