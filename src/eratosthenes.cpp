#include <cmath>
#include <vector>

template <class Integer>
std::vector<Integer> eratosthenes(
  Integer first, Integer last
)
{
  //입력이 유효하지 않으면 빈 벡터 반환
  if(last<=1 || first>last)
    return std::vector();
  
  std::vector<Integer> all_number;
 
  //모든 후보를 할당.
  for(Integer i = first; i<=last; i++)
  {
    all_number.push_back(i);
  }
  
  std::vector<bool> prime_checker(all_number.size(), true);
  
  Integer divisor = 2;
  Integer root = sqrt(last);
  while(divisor<=root)
  {
    Integer i = divisor; //나눌 수
    int index = 0; //인덱스 위치
    while(i<first)
    {
      i+=divisor;
      index+=divisor;
    }
    while(i<=last)
    {
      prime_checker[index] = false;
      
      i+=divisor;
      index+=divisor;
    }
    
    divisor++;
  }
  
  std::vector<Integer> primes;
  for(int i=0; i<all_number; i++)
  {
    if(prime_checker[i])
      primes.push_back(all_number[i]);
  }
  
  return primes;
}
