#ifndef TRANSLITERATOR_H
#define TRANSLITERATOR_H

#include <vector>
#include <string>
#include <map>
#include <istream>

#include <faraheedi.h>

namespace Faraheedi{

  class Transliterator
  {
    std::vector<std::string> headers;
    std::vector<std::pair<std::string,std::string> > dictionary;

    void getHeaders(const std::string &);
    void getEntries(const std::string &);

    HIDE_EVIL_CTORS(Transliterator);

    public:
    explicit Transliterator(std::istream &is);
    void transliterate(std::string *s, const std::string &target);
  };

}

#endif //TRANSLITERATOR_H
