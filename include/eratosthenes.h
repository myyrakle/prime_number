template <class Integer>
std::vector<Integer> eratosthenes(Integer first, Integer last)
{
    //최소 시작 도메인을 [2, last]로 맞춤
    if (first <= 1)
    {
        first = 2;
    }

    //입력이 유효하지 않으면 빈 벡터 반환
    if (last <= 1 || first > last)
    {
        return std::vector<Integer>();
    }


    std::vector<Integer> all_number;
    all_number.reserve(last - first + 1);

    //모든 후보를 할당
    for (Integer i = first; i <= last; i++)
    {
        all_number.push_back(i);
    }

    std::vector<bool> prime_checker(all_number.size(), true);

    for (Integer divisor = 2; divisor * divisor <= last; ++divisor)
    {
        //first 이상인 divisor의 최소 배수 구하기
        Integer offset = (first + divisor - 1) / divisor * divisor;
        int index = offset - first;

        //자기 자신은 소수 취급해야 하므로 divisor를 더함
        //4의 경우는 소수가 아니지만 이는 2에서 이미 걸러졌으므로 상관없음
        if (offset == divisor)
        {
            index += divisor;
        }

        while (index < all_number.size())
        {
            prime_checker[index] = false;
            index += divisor;
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