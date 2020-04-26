//무식한 구현
//N*√N의 복잡도를 가짐

#include <cmath>
#include <vector>

template <class Integer>
bool is_prime_number(Integer n)
{
   if(n<=1)
      return false;
    
   if(n%2==0)
     return false;
  
   Integer divisor = 2;
  
   Integer root = (Integer)sqrt(n);
   while(divisor <= root)
   {
     if(n%divisor == 0)
       return false;
      
     divisor++;
   }
  
   return true;
}

template <class Integer>
std::vector<Integer> prime_numbers(
  Integer begin, Integer end
)
{
  std::vector<Integer> primes;
  
  while(begin!=end)
  {
    if(begin<=1)
    {
      //nothing
    }
    else
    {
      if(is_prime_number(begin))
        primes.push_back(begin);
    }
    
    begin++;
  }
  
  return primes;
}
