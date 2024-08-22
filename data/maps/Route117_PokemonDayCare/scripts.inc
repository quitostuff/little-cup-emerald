Route117_PokemonDayCare_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_EventScript_PkmnBreeder::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DAYCARE_SLUGMA, Route117_PokemonDayCare_EventScript_SlugmaAbility
	goto Route117_PokemonDayCare_EventScript_DaycareGift
	end

Route117_PokemonDayCare_EventScript_DaycareGift::
	msgbox Route117_PokemonDayCare_Text_PleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SLUGMA
	givemon SPECIES_SLUGMA, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route117_PokemonDayCare_EventScript_ReceiveSlugmaParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route117_PokemonDayCare_EventScript_ReceiveSlugmaPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route117_PokemonDayCare_EventScript_ReceiveSlugmaParty::
	call Route117_PokemonDayCare_EventScript_ReceivedSlugmaFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route117_PokemonDayCare_EventScript_SlugmaAbility
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route117_PokemonDayCare_EventScript_SlugmaAbility
	end

Route117_PokemonDayCare_EventScript_ReceiveSlugmaPC::
	call Route117_PokemonDayCare_EventScript_ReceivedSlugmaFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route117_PokemonDayCare_EventScript_SendSlugmaToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route117_PokemonDayCare_EventScript_SendSlugmaToPC
	end

Route117_PokemonDayCare_EventScript_SendSlugmaToPC::
	call Common_EventScript_TransferredToPC
	goto Route117_PokemonDayCare_EventScript_SlugmaAbility
	end

Route117_PokemonDayCare_EventScript_ReceivedSlugmaFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route117_PokemonDayCare_Text_PlayerReceivedSlugma
	waitmessage
	waitfanfare
	setflag FLAG_RECEIVED_DAYCARE_SLUGMA
	bufferspeciesname STR_VAR_1, SPECIES_SLUGMA
	return

Route117_PokemonDayCare_EventScript_SlugmaAbility::
	msgbox Route117_PokemonDayCare_Text_SlugmaHatchesEggs, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Text_PleaseTakePokemon:
	.string "I've been hatching a lot of POKéMON\n"
	.string "eggs from the daycare lately.\p"
	.string "It takes time for these babies to hatch,\n"
	.string "but I've noticed that it doesn't\l"
	.string "take nearly as long when I have\l"
	.string "a SLUGMA in my party.\p"
	.string "How about I give you a SLUGMA\n"
	.string "to help you hatch some POKEMON eggs?\p"
	.string "Don't worry, I have plenty of\n"
	.string "SLUGMA from all of the eggs that\l"
	.string "I've been hatching lately.$"

Route117_PokemonDayCare_Text_PlayerReceivedSlugma:
	.string "{PLAYER} received SLUGMA!$"

Route117_PokemonDayCare_Text_SlugmaHatchesEggs:
	.string "Some people say that other POKéMON\n"
	.string "also have the ability to hatch\l"
	.string "POKéMON eggs faster.\p"
	.string "Those POKéMON all have the\n"
	.string "ability FLAME BODY.\p"
	.string "But my SLUGMA has MAGMA ARMOR and\n"
	.string "it still helps hatch eggs just fine…$"
