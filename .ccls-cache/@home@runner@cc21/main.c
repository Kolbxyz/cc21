#include "game.h"
#include <stdio.h>
#include <string.h>

int turn;

int main() {
  turn = 1;
  t_game *g = game_init();

  game_loop(g);
  return 0;
}

void game_loop(t_game *g) {
  while (!is_game_finished(g)) {

    printf("\n🔵 Turn %i/5:\n", turn); // Afficher le tour actuel

    if (turn == 5) {                    // Si le tour actuel est le 5ème:
      game_end(g);                      // Prévoir la fin de la partie
    } else if (g->player->score <= 0) { // Si le score du joueur est négatif
      game_end(g);                      // Prévoir la fin de la partie
      break;                            // Arrêter la partie
    }

    print_player_coins(g->player); // Afficher le nombre de jetons du joueur
    broker_new_hand(g);            // Le croupier pioche
    player_new_hand(g);            // Le joueur pioche
    print_player_hand(g->player);  // Afficher la main du joueur
    broker_place_bet(g);           // Le croupier mise
    player_place_bet(g);           // Le joueur mise
    /*sum_player_hand(g->player);  Le joueur choisi la valeur de ses Valets (1
     * ou 11) et cette function "return" le score du joueur */

    int in_hand = player_ask_cards(g);       // La main du joueur
    int p_hand = sum_player_hand(g->player); // La somme de la main du joueur
    print_turn_results(g, p_hand);           // Annoncer la fin du tour

    if (p_hand <= 21 && in_hand == 6) {
      player_jackpot(g);
    } else if (p_hand == 21) {
      player_jackpot(g); // Le joueur fait 21
    } else if (p_hand > 21) {
      player_breakthrough(g); // Le joueur fait plus que 21
    } else if (p_hand < g->broker) {
      player_lost(g); // Le joueur perd
    } else {
      player_win(g); // Le joueur gagne
    }
    turn++; // Incrémenter le tour actuel
  }

  printf("\n\nFinale result: "); // Annoncer la fin de la manche
  if (g->player->score >= 0) {
    print_player_coins(g->player); // Afficher le nombre de jetons final
  } else {
    printf("You have a debt of %i coins.", g->player->score);
  }

  int valid = 0;
  char ans[100];
  while (strcmp(ans, "no")) {
    while (!valid) {
      printf("\n\n❔ Do you wish to play again? (yes/no)\n- ");
      scanf("%[^\n]%*c", ans);
      if (!strcmp(ans, "yes") || !strcmp(ans, "no"))
        valid = 1;
      else
        printf("Invalid answer please use 'yes' or 'no'\n");
    }
    valid = 0;
    if (!strcmp(ans, "yes")) {
      main();
    }
  }
}