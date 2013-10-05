DELETE FROM script_texts WHERE entry IN (-1881001, -1881002, -1881003);
INSERT INTO script_texts (entry, content_default, content_loc8, sound, type, language, emote, comment) VALUES
(-1881001, "You are in Combat!", "Вы ноходитесь в бою!", 0, 1, 0, 0, "rank_vendor SAY_VENDOR_COMBAT"),
(-1881002, "You already have this rank!", "Вы уже имеете это звание!", 0, 1, 0, 0, "rank_vendor SAY_VENDOR_HAVE_TITLE"),
(-1881003, "Not enough murders!", "Недостаточно убийств!", 0, 1, 0, 0, "rank_vendor SAY_VENDOR_FORBID");

DELETE FROM gossip_texts WHERE entry BETWEEN -3881029 AND -3881001;
INSERT INTO gossip_texts (entry, content_default, content_loc8, comment) VALUES
(-3881001, "PvP titles..", "ПвП титулы..", "rank_vendor GOSSIP_RANK_PVP_TITLES"),
(-3881002, "Private. 25 kills", "Рядовой. 25 убийств", "rank_vendor GOSSIP_RANK_PRIVATE"),
(-3881003, "Corporal. 100 kills", "Капрал. 100 убийств", "rank_vendor GOSSIP_RANK_CORPORAL"),
(-3881004, "Sergeant. 250 kills", "Сержант. 250 убийств", "rank_vendor GOSSIP_RANK_SERGEANT"),
(-3881005, "Master sergeant. 500 kills", "Старший сержант. 500 убийств", "rank_vendor GOSSIP_RANK_MASTER_SERGEANT"),
(-3881006, "Sergeant Major. 1000 kills", "Старшина. 1000 убийств", "rank_vendor GOSSIP_RANK_SERGEANT_MAJOR"),
(-3881007, "Knight. 1500 kills", "Рыцарь. 1500 убийств", "rank_vendor GOSSIP_RANK_KNIGHT"),
(-3881008, "Knight-Lieutenant. 3000 kills", "Рыцарь-лейтенант. 3000 убийств", "rank_vendor GOSSIP_RANK_KNIGHT_LIEUTENANT"),
(-3881009, "Knight-Captain. 5000 kills", "Рыцарь-капитан. 5000 убийств", "rank_vendor GOSSIP_RANK_KNIGHT_CAPTAIN"),
(-3881010, "Knight-Champion. 7500 kills", "Рыцарь-защитник. 7500 убийств", "rank_vendor GOSSIP_RANK_KNIGHT_CHAMPION"),
(-3881011, "Lieutenant-Commander. 10000 kills", "Лейтенант-командор. 10000 убийств", "rank_vendor GOSSIP_RANK_LIEUTENANT_COMMANDER"),
(-3881012, "Commander. 15000 kills", "Командор. 15000 убийств", "rank_vendor GOSSIP_RANK_COMMANDER"),
(-3881013, "Marshal. 25000 kills", "Маршал. 25000 убийств", "rank_vendor GOSSIP_RANK_MARSHAL"),
(-3881014, "Field Marshal. 45000 kills", "Фельдмаршал. 45000 убийств", "rank_vendor GOSSIP_RANK_FIELD_MARSHAL"),
(-3881015, "Grand Marshal. 60000 kills", "Главнокомандующий. 60000 убийств", "rank_vendor GOSSIP_RANK_GRAND_MARSHAL"),
(-3881016, "Scout. 25 kills", "Разведчик. 25 убийств", "rank_vendor GOSSIP_RANK_SCOUT"),
(-3881017, "Grunt. 100 kills", "Рубака. 100 убийств", "rank_vendor GOSSIP_RANK_GRUNT"),
(-3881018, "Sergeant. 250 kills", "Сержант. 250 убийств", "rank_vendor GOSSIP_RANK_SERGEANT2"),
(-3881019, "Senior Sergeant. 500 kills", "Старший сержант. 500 убийств", "rank_vendor GOSSIP_RANK_SENIOR_SERGEANT"),
(-3881020, "First Sergeant. 1000 kills", "Старшина. 1000 убийств", "rank_vendor GOSSIP_RANK_FIRST_SERGEANT"),
(-3881021, "Stone Guard. 1500 kills", "Каменный страж. 1500 убийств", "rank_vendor GOSSIP_RANK_STONE_GUARD"),
(-3881022, "Blood Guard. 3000 kills", "Кровавый страж. 3000 убийств", "rank_vendor GOSSIP_RANK_BLOOD_GUARD"),
(-3881023, "Legionnaire. 5000 kills", "Легионер. 5000 убийств", "rank_vendor GOSSIP_RANK_LEGIONNAIRE"),
(-3881024, "Centurion. 7500 kills", "Центурион. 7500 убийств", "rank_vendor GOSSIP_RANK_CENTURION"),
(-3881025, "Champion. 10000 kills", "Защитник. 10000 убийств", "rank_vendor GOSSIP_RANK_CHAMPION"),
(-3881026, "Lieutenant General. 15000 kills", "Генерал-лейтенант. 15000 убийств", "rank_vendor GOSSIP_RANK_LIEUTENANT_GENERAL"),
(-3881027, "General. 25000 kills", "Генерал. 25000 убийств", "rank_vendor GOSSIP_RANK_GENERAL"),
(-3881028, "Warlord. 45000 kills", "Полководец. 45000 убийств", "rank_vendor GOSSIP_RANK_WARLORD"),
(-3881029, "High Warlord. 60000 kills", "Верховный полководец. 60000 убийств", "rank_vendor GOSSIP_RANK_HIGH_WARLORD");

