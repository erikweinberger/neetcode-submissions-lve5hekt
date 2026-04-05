class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        openb = 0
        closedb = 0
        res = []

        self.req_par(res, openb, closedb, n, curr_str='')

        return res
    
    def req_par(self, res: list, openb: int, closedb: int, n: int, curr_str: str):
        if closedb == n:
            print(closedb, openb)
            res.append(curr_str)

        elif openb == n:
            closedb += 1
            curr_str += ')'
            self.req_par(res, openb, closedb, n, curr_str)
        
        elif openb == closedb:
            openb += 1
            curr_str += '('
            self.req_par(res, openb, closedb, n, curr_str)
                    
        else:
            self.req_par(res, openb + 1, closedb, n, curr_str + '(')
            self.req_par(res, openb, closedb + 1, n, curr_str + ')')


        