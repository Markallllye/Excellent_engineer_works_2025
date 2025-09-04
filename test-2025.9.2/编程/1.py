print("请输入序列长度和序列：")
# 输入序列长度
n = int(input())
# 输入序列
arr = list(map(int, input().split()))

# 快速排序函数
def quick_sort(lst):
    if len(lst) <= 1:
        return lst
    pivot = lst[len(lst) // 2]
    left = [x for x in lst if x < pivot]
    middle = [x for x in lst if x == pivot]
    right = [x for x in lst if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

# 对数组进行快速排序
sorted_arr = quick_sort(arr)
# 输出升序排列后的序列
print(" ".join(map(str, sorted_arr)))