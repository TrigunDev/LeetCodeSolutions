class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        result = [0] * n
        st = []

        for i in range(n):
            while st and temperatures[st[-1]] < temperatures[i]:
                result[st[-1]] = i - st[-1]
                st.pop()

            st.append(i)

        return result