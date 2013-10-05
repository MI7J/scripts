/* Copyright (C) 2006 - 2011 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* Copyright (C) 2011 MangosR2
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

/* ScriptData
SDName: npc_rank_vendor
SD%Complete: 33%
SDComment: full work only of pvp titles, instance and event titles will be later...
SDAuthor: original idea by Kirito, new version by lanc
SDCategory: custom
SDVersion: 1.0
EndScriptData */

#include "precompiled.h"
#include "sc_creature.h"
#include "sc_gossip.h"

enum
{
    SAY_VENDOR_COMBAT                   = -1881001,
    SAY_VENDOR_HAVE_TITLE               = -1881002,
    SAY_VENDOR_FORBID                   = -1881003,

    GOSSIP_ITEM_PVP_TITLES              = -3881001,
    //GOSSIP_ITEM_INSTANCE_TITLES         = ,
    //GOSSIP_ITEM_EVENT_TITLES            = ,

    // PVP rank's - Aliance
    GOSSIP_RANK_PRIVATE                 = -3881002,
    GOSSIP_RANK_CORPORAL                = -3881003,
    GOSSIP_RANK_SERGEANT                = -3881004,
    GOSSIP_RANK_MASTER_SERGEANT         = -3881005,
    GOSSIP_RANK_SERGEANT_MAJOR          = -3881006,
    GOSSIP_RANK_KNIGHT                  = -3881007,
    GOSSIP_RANK_KNIGHT_LIEUTENANT       = -3881008,
    GOSSIP_RANK_KNIGHT_CAPTAIN          = -3881009,
    GOSSIP_RANK_KNIGHT_CHAMPION         = -3881010,
    GOSSIP_RANK_LIEUTENANT_COMMANDER    = -3881011,
    GOSSIP_RANK_COMMANDER               = -3881012,
    GOSSIP_RANK_MARSHAL                 = -3881013,
    GOSSIP_RANK_FIELD_MARSHAL           = -3881014,
    GOSSIP_RANK_GRAND_MARSHAL           = -3881015,

    // PVP rank's - Horde
    GOSSIP_RANK_SCOUT                   = -3881016,
    GOSSIP_RANK_GRUNT                   = -3881017,
    GOSSIP_RANK_SERGEANT2               = -3881018,
    GOSSIP_RANK_SENIOR_SERGEANT         = -3881019,
    GOSSIP_RANK_FIRST_SERGEANT          = -3881020,
    GOSSIP_RANK_STONE_GUARD             = -3881021,
    GOSSIP_RANK_BLOOD_GUARD             = -3881022,
    GOSSIP_RANK_LEGIONNAIRE             = -3881023,
    GOSSIP_RANK_CENTURION               = -3881024,
    GOSSIP_RANK_CHAMPION                = -3881025,
    GOSSIP_RANK_LIEUTENANT_GENERAL      = -3881026,
    GOSSIP_RANK_GENERAL                 = -3881027,
    GOSSIP_RANK_WARLORD                 = -3881028,
    GOSSIP_RANK_HIGH_WARLORD            = -3881029,
};

bool GossipHello_npc_rank_vendor(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_BATTLE, GOSSIP_ITEM_PVP_TITLES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    /*pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_VENDOR, GOSSIP_ITEM_INSTANCE_TITLES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_TABARD, GOSSIP_ITEM_EVENT_TITLES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);*/
    pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetObjectGuid());
    return true;
}

void vendorSetTitle(Player* pPlayer, uint32 uiTitle, Creature* pCreature)
{
    if (const CharTitlesEntry* titleEntry = GetTitlesEntryStore()->LookupEntry(uiTitle))
    {
        if (pPlayer->HasTitle(titleEntry))
        {
            DoScriptText(SAY_VENDOR_HAVE_TITLE, pCreature);
            return;
        }

        for (uint8 i = 1; i < 29; ++i)
        {
            if (const CharTitlesEntry* oldEntry = GetTitlesEntryStore()->LookupEntry(i))
            {
                if (pPlayer->HasTitle(oldEntry))
                    pPlayer->SetTitle(oldEntry, true);
            }
        }
        pPlayer->SetTitle(titleEntry);
        pPlayer->SetUInt32Value(PLAYER_CHOSEN_TITLE, uiTitle);
    }
}

void SendDefaultMenu_npc_rank_vendor(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    uint32 killsCount = pPlayer->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
    bool isAliance = pPlayer->GetTeam() == ALLIANCE;
    //long long int pMoney = pPlayer->GetMoney();

    if (pPlayer->isInCombat())
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        DoScriptText(SAY_VENDOR_COMBAT, pCreature);
        return;
    }

    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
        {
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_PRIVATE : GOSSIP_RANK_SCOUT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_CORPORAL : GOSSIP_RANK_GRUNT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_SERGEANT : GOSSIP_RANK_SERGEANT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_MASTER_SERGEANT : GOSSIP_RANK_SENIOR_SERGEANT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_SERGEANT_MAJOR : GOSSIP_RANK_FIRST_SERGEANT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_KNIGHT : GOSSIP_RANK_STONE_GUARD, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_KNIGHT_LIEUTENANT : GOSSIP_RANK_BLOOD_GUARD, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_KNIGHT_CAPTAIN : GOSSIP_RANK_LEGIONNAIRE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_KNIGHT_CHAMPION : GOSSIP_RANK_CENTURION, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_LIEUTENANT_COMMANDER : GOSSIP_RANK_CHAMPION, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_COMMANDER : GOSSIP_RANK_LIEUTENANT_GENERAL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14);
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_MARSHAL : GOSSIP_RANK_GENERAL, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 15);
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_FIELD_MARSHAL : GOSSIP_RANK_WARLORD, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 16);
            pPlayer->ADD_GOSSIP_ITEM_ID(GOSSIP_ICON_CHAT, isAliance ? GOSSIP_RANK_GRAND_MARSHAL : GOSSIP_RANK_HIGH_WARLORD, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 17);
            pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetObjectGuid());
        }
        break;

        case GOSSIP_ACTION_INFO_DEF + 4:
        {
            if (killsCount >= 25)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 1: 15, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 5:
        {
            if (killsCount >= 100)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 2: 16, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 6:
        {
            if (killsCount >= 250)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 3: 17, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 7:
        {
            if (killsCount >= 500)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 4: 18, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 8:
        {
            if (killsCount >= 1000)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 5: 19, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 9:
        {
            if (killsCount >= 1500)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 6: 20, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 10:
        {
            if (killsCount >= 3000)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 7: 21, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 11:
        {
            if (killsCount >= 5000)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 8: 22, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 12:
        {
            if (killsCount >= 7500)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 9: 23, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 13:
        {
            if (killsCount >= 10000)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 10: 24, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 14:
        {
            if (killsCount >= 15000)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 11: 25, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 15:
        {
            if (killsCount >= 25000)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 12: 26, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 16:
        {
            if (killsCount >= 45000)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 13: 27, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        case GOSSIP_ACTION_INFO_DEF + 17:
        {
            if (killsCount >= 60000)
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                vendorSetTitle(pPlayer, isAliance ? 14: 28, pCreature);
            }
            else
            {
                pPlayer->CLOSE_GOSSIP_MENU();
                DoScriptText(SAY_VENDOR_FORBID, pCreature);
            }
            break;
        }
        default:
            break;
    }
}

bool GossipSelect_npc_rank_vendor(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiSender == GOSSIP_SENDER_MAIN)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        SendDefaultMenu_npc_rank_vendor(pPlayer, pCreature, uiAction);
    }
    return true;
}

void AddSC_npc_rank_vendor()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "npc_rank_vendor";
    pNewScript->pGossipHello = &GossipHello_npc_rank_vendor;
    pNewScript->pGossipSelect = &GossipSelect_npc_rank_vendor;
    pNewScript->RegisterSelf();
}
