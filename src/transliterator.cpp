#include <transliterator.h>
using namespace Faraheedi;

using namespace std;

#ifdef BOOST

#include <boost/regex.hpp>
using boost::regex;
using boost::sregex_token_iterator;

#elif STD_REGEX

#include <regex>

#endif

void Transliterator::getEntries(const string &line){
  
  regex RE(":");
  int pos = 0;
  for(sregex_token_iterator i(line.begin(), line.end(), RE, -1), j;
      i != j;
      ++i, ++pos){
    pair<string, string> entry(headers[pos],*i);
    dictionary.push_back(entry);
  }

}

void Transliterator::getHeaders(const string &line){
  regex RE(":");
  for(sregex_token_iterator i(line.begin(), line.end(), RE, -1), j;
      i != j;
      ++i){
    headers.push_back(*i);
  }
}

Transliterator::Transliterator(istream &is){
  
  string line;
  getline(is, line);
  getHeaders(line);

  for(string line; getline(is,line);){
    getEntries(line);
  }

}

void Transliterator::transliterate(string *s, const string &target){
}

