Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_SpendBottleCap
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	trainerbattle_single TRAINER_MISTY, Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, Route109_SeashoreHouse_Text_MistyDefeated, Route109_SeashoreHouse_EventScript_GiveRewards, NO_MUSIC
	release
	end

Route109_SeashoreHouse_EventScript_GiveRewards::
	msgbox Route109_SeashoreHouse_Text_GiveBottlesAndTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_WATER_PULSE, 3
	giveitem ITEM_BOTTLE_CAP, 3
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	msgbox Route109_SeashoreHouse_Text_ExplainBottleCaps, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_SpendBottleCap::
	msgbox Route109_SeashoreHouse_Text_WannaRaiseAnIV, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_WhichPokemon
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_WhichPokemon::
	checkitem ITEM_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NoBottleCap
	msgbox Route109_SeashoreHouse_Text_PickPokemon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge Route109_SeashoreHouse_EventScript_CancelIvSelect
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq Route109_SeashoreHouse_EventScript_CantRaiseEgg
	goto Route109_SeashoreHouse_EventScript_WhichStat

Route109_SeashoreHouse_EventScript_WhichStat::
	message Route109_SeashoreHouse_Text_WhichStat
	waitmessage
	multichoice 0, 0, MULTI_BOTTLE_CAP_STATS, FALSE
	switch VAR_RESULT
	case 0, Route109_SeashoreHouse_EventScript_RaiseHP
	case 1, Route109_SeashoreHouse_EventScript_RaiseAtk
	case 2, Route109_SeashoreHouse_EventScript_RaiseDef
	case 3, Route109_SeashoreHouse_EventScript_RaiseSpAtk
	case 4, Route109_SeashoreHouse_EventScript_RaiseSpDef
	case 5, Route109_SeashoreHouse_EventScript_RaiseSpeed
	goto Route109_SeashoreHouse_EventScript_CancelIvSelect
	end

Route109_SeashoreHouse_EventScript_RaiseHP::
	msgbox Route109_SeashoreHouse_Text_NotQuiteMax, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_RaiseHPTo30
	goto_if_eq VAR_RESULT, NO, Route109_SeashoreHouse_EventScript_RaiseHPToMax
	end

Route109_SeashoreHouse_EventScript_RaiseAtk::
	msgbox Route109_SeashoreHouse_Text_NotQuiteMax, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_RaiseAtkTo30
	goto_if_eq VAR_RESULT, NO, Route109_SeashoreHouse_EventScript_RaiseAtkToMax
	end

Route109_SeashoreHouse_EventScript_RaiseDef::
	msgbox Route109_SeashoreHouse_Text_NotQuiteMax, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_RaiseDefTo30
	goto_if_eq VAR_RESULT, NO, Route109_SeashoreHouse_EventScript_RaiseDefToMax
	end

Route109_SeashoreHouse_EventScript_RaiseSpAtk::
	msgbox Route109_SeashoreHouse_Text_NotQuiteMax, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_RaiseSpAtkTo30
	goto_if_eq VAR_RESULT, NO, Route109_SeashoreHouse_EventScript_RaiseSpAtkToMax
	end

Route109_SeashoreHouse_EventScript_RaiseSpDef::
	msgbox Route109_SeashoreHouse_Text_NotQuiteMax, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_RaiseSpDefTo30
	goto_if_eq VAR_RESULT, NO, Route109_SeashoreHouse_EventScript_RaiseSpDefToMax
	end

Route109_SeashoreHouse_EventScript_RaiseSpeed::
	msgbox Route109_SeashoreHouse_Text_NotQuiteMax, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_RaiseSpeedTo30
	goto_if_eq VAR_RESULT, NO, Route109_SeashoreHouse_EventScript_RaiseSpeedToMax
	end

Route109_SeashoreHouse_EventScript_RaiseHPTo30::
	setvar VAR_0x8000, 30
	special SetHpIVs
	msgbox Route109_SeashoreHouse_Text_StatWasIncreased, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP
	release
	end

Route109_SeashoreHouse_EventScript_RaiseHPToMax::
	setvar VAR_0x8000, 31
	special SetHpIVs
	msgbox Route109_SeashoreHouse_Text_StatWasIncreased, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP
	release
	end

Route109_SeashoreHouse_EventScript_RaiseAtkTo30::
	setvar VAR_0x8001, 30
	special SetAtkIVs
	msgbox Route109_SeashoreHouse_Text_StatWasIncreased, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP
	release
	end

Route109_SeashoreHouse_EventScript_RaiseAtkToMax::
	setvar VAR_0x8001, 31
	special SetAtkIVs
	msgbox Route109_SeashoreHouse_Text_StatWasIncreased, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP
	release
	end

Route109_SeashoreHouse_EventScript_RaiseDefTo30::
	setvar VAR_0x8002, 30
	special SetDefIVs
	msgbox Route109_SeashoreHouse_Text_StatWasIncreased, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP
	release
	end

Route109_SeashoreHouse_EventScript_RaiseDefToMax::
	setvar VAR_0x8002, 31
	special SetDefIVs
	msgbox Route109_SeashoreHouse_Text_StatWasIncreased, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP
	release
	end

Route109_SeashoreHouse_EventScript_RaiseSpAtkTo30::
	setvar VAR_0x8005, 30
	special SetSpAtkIVs
	msgbox Route109_SeashoreHouse_Text_StatWasIncreased, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP
	release
	end

Route109_SeashoreHouse_EventScript_RaiseSpAtkToMax::
	setvar VAR_0x8005, 31
	special SetSpAtkIVs
	msgbox Route109_SeashoreHouse_Text_StatWasIncreased, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP
	release
	end

Route109_SeashoreHouse_EventScript_RaiseSpDefTo30::
	setvar VAR_0x8006, 30
	special SetSpDefIVs
	msgbox Route109_SeashoreHouse_Text_StatWasIncreased, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP
	release
	end

Route109_SeashoreHouse_EventScript_RaiseSpDefToMax::
	setvar VAR_0x8006, 31
	special SetSpDefIVs
	msgbox Route109_SeashoreHouse_Text_StatWasIncreased, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP
	release
	end

Route109_SeashoreHouse_EventScript_RaiseSpeedTo30::
	setvar VAR_0x8003, 30
	special SetSpdIVs
	msgbox Route109_SeashoreHouse_Text_StatWasIncreased, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP
	release
	end

Route109_SeashoreHouse_EventScript_RaiseSpeedToMax::
	setvar VAR_0x8003, 31
	special SetSpdIVs
	msgbox Route109_SeashoreHouse_Text_StatWasIncreased, MSGBOX_DEFAULT
	removeitem ITEM_BOTTLE_CAP
	release
	end

Route109_SeashoreHouse_EventScript_NoBottleCap::
	msgbox Route109_SeashoreHouse_Text_NoBottleCap, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_CancelIvSelect::
	msgbox Route109_SeashoreHouse_Text_CancelIvSelect, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_CantRaiseEgg::
	msgbox Route109_SeashoreHouse_Text_CantRaiseEgg, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Hi, you're a new face!\p"
	.string "But then again, so am I to\n"
	.string "this region.\p"
	.string "I'm Misty, the gym leader in\n"
	.string "Kanto's Cerulean City.\p"
	.string "Let's see if you're strong enough\n"
	.string "to defeat the other customers here.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "How did a gym leader like me\n"
	.string "end up owning a store in\l"
	.string "another region?\p"
	.string "I don't!\p"
	.string "This is actually a promotional deal\n"
	.string "with the real owner here.$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Woah, you're not too shabby\n"
	.string "at battling, huh.\p"
	.string "But let's see how well you stand up\n"
	.string "against a Kanto Gym Leader!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, but hey, your BAG's jammed full.\n"
	.string "I'll hang on to these for you.$"

Route109_SeashoreHouse_Text_GiveBottlesAndTM:
	.string "Wow, you still beat me even though\n"
	.string "I was going all out during that battle.\p"
	.string "I would give you a Cascade Badge, but\n"
	.string "that probably doesn't mean much\l"
	.string "since we're not in Kanto.\p"
	.string "Hmm, how about some Bottle Caps?\n"
	.string "Oh, I also have a couple of copies\l"
	.string "of this TM with me as well.$"

Route109_SeashoreHouse_Text_ExplainBottleCaps:
	.string "What can you do with these Bottle Caps?\p"
	.string "You can give one to me and I can\n"
	.string "maximize the Individual Value of a\l"
	.string "POKéMON in a given stat!\p"
	.string "Or I could increase it so it's almost\n"
	.string "at its maximum value.\p"
	.string "But why would you not want to maximize\n"
	.string "an Individual Value in a stat?\p"
	.string "It has something to do with the\n"
	.string "POWER that's HIDDEN with a POKéMON…$"

Route109_SeashoreHouse_Text_WannaRaiseAnIV:
	.string "Do you want to raise a POKéMON's?\n"
	.string "Individual Value?\p"
	.string "You pick the POKéMON and stat,\n"
	.string "I'll do the raising.$"

Route109_SeashoreHouse_Text_PickPokemon:
	.string "Which POKéMON would you like\n"
	.string "to become stronger?$"

Route109_SeashoreHouse_Text_WhichStat:
	.string "And which stat do you want me\n"
	.string "to increase?$"

Route109_SeashoreHouse_Text_NotQuiteMax:
	.string "Would you like me to increase\n"
	.string "their Individual Value to 30\l"
	.string "instead of the usual 31?$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "No?\n"
	.string "That's too bad.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "If you're looking for a battle in the\n"
	.string "SEASHORE HOUSE, you'll find no\l"
	.string "hotter TRAINER than me, matey!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "That was a hot battle!\n"
	.string "I can accept that loss, matey!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Whenever I'm in SLATEPORT, I enjoy\n"
	.string "hot battles and ice-cold SODA POP!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Boring battles aren't worth the effort.\p"
	.string "Fiery hot battles are what toughen up\n"
	.string "TRAINERS and POKéMON!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "That's hot!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Whew, I'm all thirsty.\n"
	.string "Maybe I'll have a SODA POP.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "I'm going to show you how great\n"
	.string "my POKéMON are, but don't cry!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…I lost, but I won't cry…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "If one of my POKéMON knew the move\n"
	.string "for carrying me across water on its\l"
	.string "back, I could get rid of this inner tube.$"

Route109_SeashoreHouse_Text_MistyDefeated:
	.string "You're the real deal!$"

Route109_SeashoreHouse_Text_StatWasIncreased:
	.string "Your stat was increased!$"

Route109_SeashoreHouse_Text_NoBottleCap:
	.string "You don't have any Bottle Caps\n"
	.string "right now.\p"
	.string "Come back when you have\n"
	.string "a Bottle Cap.$"

Route109_SeashoreHouse_Text_CancelIvSelect:
	.string "Still need to think about which\n"
	.string "stat to raise? That's fine!\p"
	.string "Come back later when you've figured\n"
	.string "out what you want.$"

Route109_SeashoreHouse_Text_CantRaiseEgg:
	.string "I can't raise an Individual Value\n"
	.string "of an EGG.$"
