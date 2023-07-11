def groupAnagrams(strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        sorted_list = []
        for i in strs:
               a = sorted(i)
               b = "".join(a)
               sorted_list.append(b)
        print("sorted_list", sorted_list)
        res_list = []

        for i in range(len(sorted_list)):
              for j in range(i + 1, len(sorted_list)):
                    if sorted_list[i] == sorted_list[j]:
                           res_list.append(i)

        print("res_list", res_list)







strs = ["eat","tea","tan","ate","nat","bat"]
groupAnagrams(strs)

#Input: strs = ["eat","tea","tan","ate","nat","bat"]
#sorted_list ['aet', 'aet', 'ant', 'aet', 'ant', 'abt']

#sorted_output [[],[],[]]
#Output: [["bat"],["nat","tan"],["ate","eat","tea"]]