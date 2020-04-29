#include <cmath>
#include <vector>

template <class Integer>
std::vector<Integer> eratosthenes(Integer first, Integer last)
{
    //입력이 유효하지 않으면 빈 벡터 반환
    if (last <= 1 || first > last)
    {
        return std::vector<Integer>();
    }

    //최소 시작 도메인을 [2, last]로 맞춤
    if (first < 2)
    {
        first = 2;
    }

    std::vector<Integer> all_number; //모든 후보군의 벡터
    all_number.reserve(last - first + 1);

    //모든 후보를 할당
    for (Integer i = first; i <= last; i++)
    {
        all_number.push_back(i);
    }

    //소수 체크리스트
    std::vector<bool> prime_checker(all_number.size(), true);

    for (Integer divisor = 2; divisor * divisor <= last; ++divisor)
    {
        //first 이상인 divisor의 최소 배수 구하기
        Integer offset = (first + divisor - 1) / divisor * divisor;
        int index = offset - first;

        //문제의 조건문.
        //n의 약수의 배수들이 걸러졌다면, n의 배수는 거를 필요가 없을 거란 생각
        //if(prime_checker[index]==true)  
        {
            //자기 자신은 소수 취급해야 하므로 divisor를 더함
            //4의 경우는 소수가 아니지만 이는 2에서 이미 걸러졌으므로 상관없음
            if (offset == divisor)
            {
                index += divisor;
            }

            //divisor의 배수를 전부 걸러냄
            while (index < all_number.size())
            {
                prime_checker[index] = false;
                index += divisor;
            }
        }
    }

    //걸러낸 소수 추출
    std::vector<Integer> primes;
    for (int i = 0; i < all_number.size(); i++)
    {
        if (prime_checker[i])
        {
            primes.push_back(all_number[i]);
        }
    }

    return primes;
}