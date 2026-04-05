class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        fleets = 0

        pos_speed = [(pos, speed) for pos, speed in zip(position, speed)]
        pos_speed.sort(key=lambda x: -x[0])

        print(pos_speed)

        curr_arrival = 0
        for pos, speed in pos_speed:
            new_arrival = (target - pos) / speed
            print(f"for start pos = {pos}, arrival: {new_arrival}")
            if new_arrival > curr_arrival:
                fleets += 1
                curr_arrival = new_arrival
        
        return fleets
