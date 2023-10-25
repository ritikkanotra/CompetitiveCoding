import pandas as pd

def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    '''
    # SDE - Code
    cons_num = set()
    idx = 1
    nums = logs['num']
    while idx<len(nums)-1:
        if nums[idx-1] == nums[idx] == nums[idx+1]:
            cons_num.add(nums[idx])
            idx += 3
        elif nums[idx] != nums[idx+1]:
            idx += 2
        elif nums[idx-1] != nums[idx]:
            idx += 1            
    return pd.DataFrame({'ConsecutiveNums':list(cons_num)})
    '''

    # Analyst - Code
    uniqueValues = lambda lst: lst.nunique()==1
    logs['is_consecutive'] = logs['num']\
        .rolling(window=3, center=True, min_periods=3)\
        .apply(uniqueValues)

    print(logs.query('is_consecutive==1.0')[['num']]\
          .drop_duplicates()\
            .rename(columns={"num":'ConsecutiveNums'}))



df = pd.read_csv('D:\Data Science\Data-Science-Learning\Data-Science-Learning\Leetcode - DSA Practice\Consecutive Numbers\logs.csv')
print(consecutive_numbers(df))
# print(df)