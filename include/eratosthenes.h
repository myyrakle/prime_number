#include <cmath>
#include <vector>

template <class Integer>
std::vector<Integer> eratosthenes(Integer first, Integer last)
{
  //입력이 유효하지 않으면 빈 벡터 반환
  if(last<=1 || first>last)
    return std::vector<Integer>();
  
  std::vector<Integer> all_number;
  all_number.reserve(last-first+1);
 
  //모든 후보를 할당.
  for(Integer i = first; i<=last; i++)
  {
    all_number.push_back(i);
  }
  
  std::vector<bool> prime_checker(all_number.size(), true);

  //1 제외
  if(first<=1)
  {
    prime_checker[(1-first)] = false;
  }
  
  //걸러내기 시작
  Integer divisor = 2;
  Integer root = sqrt(last);
  while(divisor<=root)
  {
    int index = 0; //인덱스 위치
    //나눌 수를 first보다 크거나 같은 최소배수로 설정
    if(first<divisor)
    {
       index += (divisor-first);
    }

    index+=divisor; //제수 자신은 제외

    while(index<all_number.size())
    {
      prime_checker[index] = false;
      index+=divisor;
    }
    
    divisor++;
  }
  
  //걸러낸 소수 추출
  std::vector<Integer> primes;
  for(int i=0; i<all_number.size(); i++)
  {
    if(prime_checker[i])
      primes.push_back(all_number[i]);
  }
  
  return primes;
}
