import os

def mergesort(array, left, right):
    if left == right:
        return [array[left]]
    # elif right == left + 1:
    #     return [array[left]]
    else:
        sortedArray = []
        length = right - left + 1
        m = (left + right)//2
        print("m = ", m)
        print("call: mergesort( array,{},{})".format(left, m))
        left_array = mergesort(array, left, m)
        print("call: mergesort( array,{},{})".format(m+1, right))
        right_array = mergesort(array, m+1, right)
        
        # i, j = left, m+1
        i, j = 0, 0
        while len(sortedArray) != length:
            # print(len(sortedArray))
            # print(sortedArray)
            # print('i: {}, m: {}'.format(i, m))
            # print('j: {}, right: {}'.format(j, right))
            if j == len(right_array):
                sortedArray.extend(left_array[i:])
                break
            if i == len(left_array):
                sortedArray.extend(right_array[j:])
                break
            if right_array[j] < left_array[i]:
                # inversion += m-left+1
                sortedArray.append(right_array[j])
                j += 1
                continue
            if right_array[j] > left_array[i]:
                # inversion += m-left+1
                sortedArray.append(left_array[i])
                i += 1
                continue

        return sortedArray


def mergesort_v2(array, left, right):
    if left == right:
        return [array[left]]
    else:
        sortedArray = []
        length = right - left + 1
        m = (left + right)//2
        print("m = ", m)
        # print("call: mergesort( array,{},{})".format(left, m))
        left_array = mergesort(array, left, m)
        # print("call: mergesort( array,{},{})".format(m+1, right))
        right_array = mergesort(array, m + 1, right)
        
        # i, j = left, m+1
        i, j = 0, 0
        while len(sortedArray) != length:
            # print(len(sortedArray))
            # print(sortedArray)
            # print('i: {}, m: {}'.format(i, m))
            # print('j: {}, right: {}'.format(j, right))
            if j == right - m:
                sortedArray.extend(left_array[i:])
                break
            if i == m - left + 1:
                sortedArray.extend(right_array[j:])
                break
            if right_array[j] < left_array[i]:
                # inversion += m-left+1
                sortedArray.append(right_array[j])
                j += 1
                continue
            if right_array[j] > left_array[i]:
                # inversion += m-left+1
                sortedArray.append(left_array[i])
                i += 1
                continue

        return sortedArray


if __name__ == "__main__":
    array = [5, 3, 11, 8, 4, 9]
    array_sort = mergesort_v2(array, 0, 5)
    print("sorted array is:", array_sort)
    # print("inversion number is:", num_inversion)
