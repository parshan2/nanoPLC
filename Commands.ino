
void ExcuteCommand()
{

    if (Serial.available() == 0)
        return;

    // read the incoming string:
    String input = Serial.readString();
    input.trim();
    input.toUpperCase();

    Serial.print("Command: ");
    Serial.println(input);

    String command = "";
    String value = "";
    if (input.indexOf("=") > 0)
    {
        command = GetStringPart(input, '=', 0);
        value = GetStringPart(input, '=', 1);
    }
    else
    {
        command = input;
    }

    // if (command == "MOTOR_RUN_TIME")
    // {
    //     MOTOR_RUN_TIME = value.toInt();
    //     SaveMotorRuntime(MOTOR_RUN_TIME);
    //     Serial.print("Setting Saved. MOTOR_RUN_TIME=");
    //     Serial.println(MOTOR_RUN_TIME);
    //     return;
    // }

    if (command == "FURNACE_CYCLE_TIME")
    {
        FURNACE_CYCLE_TIME = value.toInt();
        SaveFurnaceCycleTime(FURNACE_CYCLE_TIME);
        Serial.print("Setting Saved. FURNACE_CYCLE_TIME=");
        Serial.println(FURNACE_CYCLE_TIME);
        return;
    }

    if (command == "LIFTER_LIMIT_TIMEOUT")
    {
        LIFTER_LIMIT_TIMEOUT = value.toInt();
        SaveLifterTimeout(LIFTER_LIMIT_TIMEOUT);
        Serial.print("Setting Saved. LIFTER_LIMIT_TIMEOUT=");
        Serial.println(LIFTER_LIMIT_TIMEOUT);
        return;
    }

    if (command == "TOTAL_CYCLES_RESET")
    {
        TOTAL_CYCLES = 0;
        SaveCycleCount(TOTAL_CYCLES);
        Print("Cycle Counter reset successfully.");
        return;
    }

    if (command == "SETTINGS")
    {
        ShowCurrentSettings();
        return;
    }

    if (command == "RESETSETTINGS")
    {
        //MOTOR_RUN_TIME = 5;
        //SaveMotorRuntime(MOTOR_RUN_TIME);
        FURNACE_CYCLE_TIME = 45;
        SaveFurnaceCycleTime(FURNACE_CYCLE_TIME);
        LIFTER_LIMIT_TIMEOUT = 15;
        SaveLifterTimeout(LIFTER_LIMIT_TIMEOUT);

        ShowCurrentSettings();
        return;
    }

    if (command == "HELP")
    {
        ShowHelp();
        return;
    }

    if (command == "RESET")
    {
        software_Reset(); //call reset
        return;
    }

    //invaid command
    Serial.print("error: {");
    Serial.print(command);
    Serial.println("} is not a valid command.");
}

void ShowCurrentSettings()
{
    Serial.println("============= Settings =============");
    //Serial.print("MOTOR_RUN_TIME=");
    //Serial.println(MOTOR_RUN_TIME);
    Serial.print("FURNACE_CYCLE_TIME=");
    Serial.println(FURNACE_CYCLE_TIME);
    Serial.print("LIFTER_LIMIT_TIMEOUT=");
    Serial.println(LIFTER_LIMIT_TIMEOUT);
    Serial.println("------------------------------------");
    Serial.print("Previous Counted Cycles: ");
    Serial.println(TOTAL_CYCLES);
    Serial.println("====================================");
}

void ShowHelp()
{
    Serial.println("============================ Commands ============================");
    Serial.println("MOTOR_RUN_TIME=000          -> set motor runing time.");
    Serial.println("FURNACE_CYCLE_TIME=000      -> set furnace heating cycle time.");
    Serial.println("LIFTER_LIMIT_TIMEOUT=000    -> lifter limit swich timeout.");
    Serial.println("TOTAL_CYCLES_RESET          -> reset cucle counter.");
    Serial.println("SETTINGS                    -> show current settings.");
    Serial.println("RESETSETTINGS               -> reset to default setting.");
    Serial.println("HELP                        -> show this help again.");
    Serial.println("RESET                       -> reset plc application.");
    Serial.println("==================================================================");
}