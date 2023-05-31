#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>
using namespace std;

class Warlock
{
public:
  Warlock(const string &name, const string &title);
  ~Warlock();

  void introduce() const;

  const string &getName() const;
  const string &getTitle() const;

  void setTitle(const string &str);

private:
  Warlock(){};
  Warlock(const Warlock &other);
  Warlock &operator=(const Warlock &other);

  string _name;
  string _title;
};

#endif // !DEBUG
