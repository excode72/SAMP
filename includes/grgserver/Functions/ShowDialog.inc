ShowDialog(playerID, dialogID, ...)
{
	switch (dialogID)
	{
		case DIALOG_ACCEPT:
		{
			new missionList[2048];
			MySQLQuery("SELECT * FROM `missions` WHERE `JobID` = '%d' AND `AcceptUserID` = '0' ORDER BY `Name` ASC", PVar:playerID[JOBID]);
			mysql_store_result();
			while (FetchMySQLRow())
			{
				if (strlen(missionList))
				{
					Format:missionList("%s\n", missionList);
				}
				Format:missionList("%s%s: %s", missionList, GetMySQLField("ID"), GetMySQLField("Name"));
			}
			mysql_free_result();
			if (strlen(missionList))
			{
				ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Auftragsannahme", missionList, "Annehmen", "Abbrechen");
			}
			else
			{
				SendClientMessage(playerID, COLOR_ERROR, "Es stehen derzeit keine Auftr�ge in deinem Beruf zur Verf�gung!");
			}
		}
		case DIALOG_ADDBUILDING_NAME:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_INPUT, "Name eingeben", "Gebe den Name f�r das Geb�ude ein.", "Erstellen", "Zur�ck");
		}
		case DIALOG_ADDBUILDING_TYPE:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Geb�udetyp ausw�hlen", "Bank\nHotel\nHaus\nPolizei", "Weiter", "Abbrechen");
		}
		case DIALOG_APPLICATION_PLAYER:
		{
			MySQLQuery("SELECT * FROM `application` WHERE `ID` = '%d' AND `application` = '0' ORDER BY `UserName` ASC", PVar:playerID[APPLICATIONID]);
			mysql_store_result();
			while (FetchMySQLRow())
			{
				new UserName[MAX_PLAYER_NAME];
				FormatNew:string[100]("Spieler: %s\n", UserName);
				ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Bewerbungs �bersicht", string, "Anschauen", "Abbrechen");
			}
			mysql_free_result();
		}
		case DIALOG_BANK_HASACCOUNT:
		{
			FormatNew:options[100]("Bank Kaufen");
			Format:options("%s\nKonto �bersicht", options);
			Format:options("%s\nKonto K�ndigen", options);
			Format:options("%s\nEinzahlen", options);
			Format:options("%s\nAuszahlen", options);
			Format:options("%s\nAktueler Zinssatz", options);
			Format:options("%s\nBewerben", options);
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Bank", options, "OK", "Abbrechen");
		}
		case DIALOG_BANK_HASNOACCOUNT:
		{
			FormatNew:options[50]("Bank Kaufen");
			Format:options("%s\nKonto Erstellen", options);
			Format:options("%s\nAktueler Zinssatz", options);
			Format:options("%s\nBewerben", options);
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Bank", options, "OK", "Abbrechen");
		}
		case DIALOG_BANK_NOACCOUNT:
		{
			FormatNew:options[200]("Bank Verkaufen");
			Format:options("%s\nFinazen �bersicht", options);
			Format:options("%s\nBewerbungs �bersicht", options);
			Format:options("%s\nEigenes Konto Erstellen", options);
			Format:options("%s\nAktueler Zinssatz", options);
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Bank", options, "OK", "Abbrechen");
		}
		case DIALOG_BANK_ACCOUNTOWNER:
		{
			FormatNew:options[300]("Bank Verkaufen");
			Format:options("%s\nFinazen �bersicht", options);
			Format:options("%s\nBewerbungs �bersicht", options);
			Format:options("%s\nEigene Konto �bersicht", options);
			Format:options("%s\nEigenes Konto K�ndigen", options);
			Format:options("%s\nEigenes Konto Einzahlen", options);
			Format:options("%s\nEigenes Konto Auszahlen", options);
			Format:options("%s\nAktueler Zinssatz", options);
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Bank", options, "OK", "Abbrechen");
		}
		case DIALOG_BANK_INPUT:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_INPUT, "Einzahlung", "Wie viel m�chtest du Einzahlen?", "Einzahlen", "Abbrechen");
		}
		case DIALOG_BANK_OUTPUT:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_INPUT, "Auszahlung", "Wie viel m�chstest du Auszahlen?", "Auszahlen", "Abbrechen");
		}
		case DIALOG_BUYHOUSE:
		{
			new string[70];
			GetStringArg(2, string);
			Format:string("Dieses Haus kann noch gekauft werden.\n\nPreis: $%s", string);
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_MSGBOX, "Haus kaufen", string, "Kaufen", "Abbrechen");
		}
		case DIALOG_BUYVEHICLE:
		{
			new string[70];
			GetStringArg(2, string);
			Format:string("M�chtest du dieses Fahrzeug Kaufen?\n\nPreis: $%s", string);
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_MSGBOX, "Fahrzeug Kaufen", string, "Ja", "Nein");
		}
		case DIALOG_CHANGEPASSWORD_STEP1:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_PASSWORD, "Accountpasswort �ndern", "Gebe dein aktuelles Passwort ein.", "Weiter", "Abbrechen");
		}
		case DIALOG_CHANGEPASSWORD_STEP2:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_PASSWORD, "Accountpasswort �ndern", "Gebe ein neues Passwort ein.", "Weiter", "Zur�ck");
		}
		case DIALOG_CHANGEPASSWORD_STEP3:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_PASSWORD, "Accountpasswort �ndern", "Wiederhole zur Sicherheit dein neues Passwort.", "OK", "Zur�ck");
		}
		case DIALOG_HOTEL_MAIN_AVAILABLE:
		{
			FormatNew:options[40]("Hotel kaufen"); // Item 0
			Format:options("%s\nZimmer mieten", options); // Item 1
			Format:options("%s\nBetreten", options); // Item 2
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Hotel", options, "OK", "Abbrechen");
		}
		case DIALOG_HOTEL_MAIN_BOUGHT:
		{
			FormatNew:options[30]("Betreten"); // Item 0
			Format:options("%s\nMieten", options); // Item 1
			Format:options("%s\nK�ndigen", options); // item 2
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Hoteloptionen", options, "OK", "Abbrechen");
		}
		case DIALOG_HOTEL_MAIN_OWNER:
		{
			FormatNew:options[50]("Betreten"); // Item 0
			Format:options("%s\nVerkaufen", options); // Item 1
			Format:options("%s\nEinnahmen", options); // item 2
			Format:options("%s\nZimmeroptionen", options); // Item 3
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Hoteloptionen", options, "OK", "Abbrechen");
		}
		case DIALOG_HOTEL_ROOMS_FREEOPTIONS:
		{
			FormatNew:options[20]("Mietpreis festlegen"); // Item 0
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Zimmeroptionen", options, "OK", "Abbrechen");
		}
		case DIALOG_HOTEL_ROOMS_LIST:
		{
			new rooms[2048];
			new string[MAX_PLAYER_NAME];
			MySQLQuery("SELECT `RoomID`, `Username` FROM `hotelrooms` LEFT JOIN `users` ON `hotelrooms`.`OwnerUserID` = `users`.`UserID` WHERE `hotelrooms`.`BuildingID` = '%d' ORDER BY `RoomID` ASC", PVar:playerID[DIALOGBUILDINGID]);
			mysql_store_result();
			while (FetchMySQLRow())
			{
				if (strlen(rooms))
				{
					Format:rooms("%s\n", rooms);
				}
				if (strlen(GetMySQLField("Username")))
				{
					Format:string(GetMySQLField("Username"));
				}
				else
				{
					Format:string("[Leer]");
				}
				Format:rooms("%%s: %s", GetMySQLField("RoomID"), string);
			}
			mysql_free_result();
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Zimmer w�hlen", rooms, "Optionen", "Abbrechen");
		}
		case DIALOG_HOTEL_ROOMS_OWNEDOPTIONS:
		{
			new options[20];
			Format:options("Mieter rauswerfen", options); // Item 0
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Zimmeroptionen", options, "OK", "Abbrechen");
		}
		case DIALOG_HOUSEOPTIONS:
		{
			FormatNew:options[20]("Betreten");// Item 0
			Format:options("%s\nVerkaufen", options);// Item 1
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Hausoptionen", options, "OK", "Abbrechen");
		}			
		case DIALOG_LOGIN:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_PASSWORD, "Login", "Bitte gebe das Passwort von deinen Account ein.", "OK", "Abbrechen");
		}
		case DIALOG_ORDERVEHICLE:
		{
			new vehicleList[2048];
			mysql_query("SELECT * FROM `vehiclemodels` ORDER BY `Name` ASC");
			mysql_store_result();
			while (FetchMySQLRow())
			{
				if (strlen(vehicleList))
				{
					Format:vehicleList("%s\n", vehicleList);
				}
				Format:vehicleList("%s%s", vehicleList, GetMySQLField("Name"));
			}
			mysql_free_result();
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Fahrzeug bestellen", vehicleList, "Bestellen", "Abbrechen");
		}
		case DIALOG_POLICE:
		{
			FormatNew:options[10]("Betreten");
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Polizei", options, "OK", "Abbrechen");
		}
		case DIALOG_POLICE_JOB:
		{
			FormatNew:options[40]("Polizeirevier kaufen");
			Format:options("%s\nBewerben", options);
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Polizei", options, "OK", "Abbrechen");
		}
		case DIALOG_POLICE_OPTIONS:
		{
			FormatNew:options[50]("Auftr�ge");
			Format:options("%s\nFinazen", options);
			Format:options("%s\nBewerbungs�bersicht", options);
			Format:options("%s\nK�ndigen", options);
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Polizei", options, "OK", "Abbrechen");
		}
		case DIALOG_RADIO:
		{
			new stations[2048];
			mysql_query("SELECT * FROM `radiostations`");
			mysql_store_result();
			while (FetchMySQLRow())
			{
				if (strlen(stations))
				{
					Format:stations("%s\n", stations);
				}
				Format:stations("%s%s", stations, GetMySQLField("Name"));
			}
			mysql_free_result();
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Radiosender w�hlen", stations, "OK", "Abbrechen");
		}
		case DIALOG_REFUEL:
		{
			new string[80];
			GetStringArg(2, string);
			PVar:playerID[CURRENTGASPRICE] = gasPrice;
			Format:string("Wie viel m�chtest du tanken (0 - %s)?\n\nAktueller Preis: $%s/Liter", string, FormatMoney(gasPrice));
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_INPUT, "Tanken", string, "Tanken", "Abbrechen");
		}
		case DIALOG_REGISTER_BIRTHDATE:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_INPUT, "Geburtsdatum eingeben", "Gebe dein Geburtsdatum im Format TT.MM.JJJJ ein.\n\nBeispiel: 05.02.1990", "Weiter", "Zur�ck");
		}
		case DIALOG_REGISTER_GENDER:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Geschlecht ausw�hlen", "M�nnlich\nWeiblich", "Weiter", "Zur�ck");
		}
		case DIALOG_REGISTER_LOCATION:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_INPUT, "Wohnort eingeben", "Gebe deinen Wohnort ein.\n\nHinweis: Kann auch ein Wohnort in San Andreas sein.", "OK", "Zur�ck");
		}
		case DIALOG_REGISTER_PASSWORD1:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_PASSWORD, "Registrieren", "Du bist noch nicht registriert!\nBitte gebe ein neues Passwort f�r deinen Account ein.", "Weiter", "Abbrechen");
		}
		case DIALOG_REGISTER_PASSWORD2:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_PASSWORD, "Passwort wiederholen", "Wiederhole zur Sicherheit dein neues Passwort.", "Weiter", "Zur�ck");
		}
		case DIALOG_RESTARTGAMEMODE:
		{
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_MSGBOX, "Gamemode neustarten", "Soll der Gamemode wirklich neugestartet werden?", "Ja", "Nein");
		}
		case DIALOG_SELECTINTERIOR:
		{
			new interiors[2048];
			new startID = getarg(3);
			new page;
			if (startID)
			{
				page = 2;
			}
			else
			{
				page = 1;
			}
			MySQLQuery("SELECT * FROM `interiors` ORDER BY `Name` ASC LIMIT %d,75", startID);
			mysql_store_result();
			while (FetchMySQLRow())
			{
				if (strlen(interiors))
				{
					Format:interiors("%s\n", interiors);
				}
				Format:interiors("%s%s", interiors, GetMySQLField("Name"));
			}
			mysql_free_result();
			switch (page)
			{
				case 1:
				{
					Format:interiors("%s\nWeiter", interiors);
				}
				case 2:
				{
					Format:interiors("%s\nZur�ck", interiors);
				}
			}
			FormatNew:string[30]("Ziel ausw�hlen (Seite %d)", page);
			PVar:playerID[INTERIORDIALOGID] = getarg(2);
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, string, interiors, "OK", "Abbrechen");
		}
		case DIALOG_STATS:
		{
			new string[1024];
			SavePlayer(playerID);
			Format:string("SELECT `users`.`UserID`, `users`.`Username`, UNIX_TIMESTAMP(`users`.`BirthDate`) AS `BirthDate`, `users`.`Location`, `users`.`MobilePhoneNumber`, `users`.`BankID`, ,`users`.`BankMoney`,`users`.`JobID`, `users`.`OnlineTime`, `users`.`LoginTime`, `banks`.`Name` AS `Bank`, `jobs`.`Name` AS `JobName` FROM `users`");
			MySQLQuery("%s LEFT JOIN (`banks`, `jobs`) ON (`banks`.`ID` = `users`.`BankID` AND `jobs`.`ID` = `users`.`JobID`) WHERE `users`.`UserID` = '%d'", string, PVar:playerID[USERID]);
			mysql_store_result();
			Format:string("ID:\t%s", GetMySQLField("UserID"));
			Format:string("%s\nName:\t%s", string, GetMySQLField("Username"));
			Format:string("%s\nAlter:\t%d Jahre", string, CalculateAge(strval(GetMySQLField("BirthDate"))));
			Format:string("%s\nWohnort:\t%s", string, GetMySQLField("Location"));
			Format:string("%s\nHandynummer:\t%s", string, GetMySQLField("MobilePhoneNumber"));
			if (strval(GetMySQLField("BankID")))
			{
				Format:string("%s\nBank:\t%s", string, GetMySQLField("Bank"));
				Format:string("%s\nBank Guthaben:\t%s", string, GetMySQLField("BankMoney"));
			}
			Format:string("%s\nGuthaben:\t$%s", string, FormatMoney(PVar:playerID[MONEY]));
			if (strval(GetMySQLField("JobID")))
			{
				Format:string("%s\nBeruf:\t%s", string, GetMySQLField("JobName"));
			}
			Format:string("%s\nSpielzeit:\t%s", string, FormatTime(strval(GetMySQLField("OnlineTime"))));
			Format:string("%s\nRegistriert seit:\t%s", string, FormatDate(GetMySQLField("RegisterTime")));
			Format:string("%s\nLetzter Login:\t%s", string, FormatDate(GetMySQLField("LoginTime")));
			mysql_free_result();
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_MSGBOX, "Personalien", string, "OK", "");
		}
		case DIALOG_TELEPORTLOCATIONS:
		{
			new locations[2048];
			mysql_query("SELECT * FROM `teleports`");
			mysql_store_result();
			while (FetchMySQLRow())
			{
				if (strlen(locations))
				{
					Format:locations("%s\n", locations);
				}
				Format:locations("%s%s", locations, GetMySQLField("Name"));
			}
			mysql_free_result();
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Teleportieren", locations, "OK", "Abbrechen");
		}
		case DIALOG_TRUCKER_JOB:
		{
			FormatNew:options[30]("Truckerfirma kaufen");
			Format:options("%s\nBewerben", options);
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Trucker", options, "OK", "Abbrechen");
		}
		case DIALOG_TRUCKER_OPTIONS:
		{
			FormatNew:options[50]("Auftr�ge");
			Format:options("%s\nFinanzen", options);
			Format:options("%s\nK�ndigen", options);
			Format:options("%s\nBewerbungs�bersicht", options);
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Trucker �bersicht", options, "OK", "Abbrechen");
		}
		case DIALOG_VEHICLEDEALER_JOB:
		{
			new options[50];
			Format:options("Autoh�ndler kaufen");
			Format:options("%s\nBewerben", options);
			Format:options("%s\nFahrzeug Kaufen", options);
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Autoh�ndler", options, "OK", "Abbrechen");
		}
		case DIALOG_VEHICLEDEALER_OPTIONS:
		{
			new options[70];
			Format:options("Fahrzeug bestellen");
			Format:options("%s\nFinanzen", options);
			Format:options("%s\nK�ndigen", options);
			Format:options("%s\nBewerbungs�bersicht", options);
			ShowPlayerDialog(playerID, dialogID, DIALOG_STYLE_LIST, "Autoh�ndler�bersicht", options, "OK", "Abbrechen");
		}
	}
}