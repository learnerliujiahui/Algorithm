
def MCS(array):
    """
    pass the whole array
    """
    if len(array) == 0:
        return 0
    elif len(array) == 1:
        return array[0]
    else:
        m = len(array)//2
        left_max = MCS(array[0: m])
        right_max = MCS(array[m:])
        
        # bellow is the most import part:
        # 'combine'
        middle_sum = array[m-1] + array[m]
        middle_sum_max = middle_sum
        
        for i in range(1, m-1):
            if array[m-1-i] + middle_sum > middle_sum_max:
                middle_sum_max = array[m-1-i] + middle_sum
            middle_sum += array[m-1-i]
        
        for j in range(1, len(array) - m):
            if array[m + j] + middle_sum > middle_sum_max:
                middle_sum_max = array[m + j] + middle_sum
            middle_sum += array[m + j]
        
        return max(middle_sum_max, left_max, right_max)


def MCS_v2(array, s, t):
    # C-style coding: do not pass the subarray
    if s == t:
        return 0
    elif t == s + 1:
        return array[s]
    else:
        m = (s + t)//2
        print('m=', m)
        print('call mcs', s, ',', m)
        left_max = MCS_v2(array, s, m)
        print('call mcs', m, ',', t)
        right_max = MCS_v2(array, m, t)
   
        middle_sum = array[m-1] + array[m]
        middle_sum_max = middle_sum

        for i in range(m-1, s, -1):
            middle_sum += array[i-1]
            if middle_sum > middle_sum_max:
                middle_sum_max = middle_sum
        
        for j in range(m, t, 1):
            middle_sum += array[j+1]
            if middle_sum > middle_sum_max:
                middle_sum_max = middle_sum
        return max(left_max, right_max, middle_sum_max)

if __name__ == '__main__':
    array = [6, -4, 7, -4, 0, 1]
    print(MCS_v2(array, 0, 5))