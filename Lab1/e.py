from collections import deque

def play_game(boris, nursik):
    boris_deck = deque(boris)
    nursik_deck = deque(nursik)
    moves = 0
    max_moves = 10**6

    while boris_deck and nursik_deck and moves < max_moves:
        boris_card = boris_deck.popleft()
        nursik_card = nursik_deck.popleft()
        
        if (boris_card == 0 and nursik_card == 9):
            boris_deck.extend([boris_card, nursik_card])
        elif (boris_card == 9 and nursik_card == 0):
            nursik_deck.extend([boris_card, nursik_card])
        elif boris_card > nursik_card:
            boris_deck.extend([boris_card, nursik_card])
        else:
            nursik_deck.extend([boris_card, nursik_card])
        
        moves += 1

    if moves == max_moves:
        return "blin nichya"
    elif boris_deck:
        return f"Boris {moves}"
    else:
        return f"Nursik {moves}"

boris_cards = list(map(int, input().split()))
nursik_cards = list(map(int, input().split()))

print(play_game(boris_cards, nursik_cards))