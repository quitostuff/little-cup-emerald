.set LOCALID_LASS, 10

GraniteCave_B2F_MapScripts::
	.byte 0

GraniteCave_B2F_EventScript_DefenseCurlTutor::
	lock
	faceplayer
	msgbox MoveTutor_Text_DefenseCurlTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DefenseCurlDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DefenseCurlDeclined
	msgbox MoveTutor_Text_DefenseCurlWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_DEFENSE_CURL
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DefenseCurlDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_DEFENSE_CURL
	msgbox MoveTutor_Text_DefenseCurlTaught, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_B2F_EventScript_LassExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_B2F_EventScript_LassExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_B2F_EventScript_LassExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_B2F_EventScript_LassExitWestEast
	removeobject LOCALID_LASS
	release
	end

MoveTutor_EventScript_DefenseCurlDeclined::
	msgbox MoveTutor_Text_DefenseCurlDeclined, MSGBOX_DEFAULT
	release
	end

GraniteCave_B2F_EventScript_LassExitNorth::
	applymovement LOCALID_LASS, GraniteCave_B2F_Movement_LassExitNorth
	waitmovement 0
	return

GraniteCave_B2F_EventScript_LassExitSouth::
	applymovement LOCALID_LASS, GraniteCave_B2F_Movement_LassExit
	waitmovement 0
	return

GraniteCave_B2F_EventScript_LassExitWestEast::
	applymovement LOCALID_LASS, GraniteCave_B2F_Movement_LassExit
	waitmovement 0
	return

GraniteCave_B2F_Movement_LassExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

GraniteCave_B2F_Movement_LassExitNorth:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end
