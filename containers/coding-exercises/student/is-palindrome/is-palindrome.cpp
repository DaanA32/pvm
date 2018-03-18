#include "is-palindrome.h"
#include <vector>


bool is_palindrome(std::vector<int> ns)
{
	for(int i=0; i < ns.size(); ++i){
		if(i >= ns.size()-i-1){
			break;
		}
		if(ns[i] != ns[ns.size()-i-1]){
			return false;
		}
	}
	return true;
}
