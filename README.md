# Arduino CAN bus sketch

This sketch reads CAN data using a [CAN bus shield](http://wiki.seeed.cc/CAN-BUS_Shield_V1.2/) (or any MCP2515 based boards) and outputs it over the serial interface.

It requires the [CAN bus shield library](https://github.com/Seeed-Studio/CAN_BUS_Shield) from Seeedstudio.

You can use this [Python script](https://github.com/alexandreblin/python-can-monitor.git) I wrote to display the data in a more readable format.

## Configuration
Make sure the variables at the top of the sketch are correct for your usage.

 * `CS_PIN` should be set to the chip select pin for your board (leave to 9 if you have the latest CAN Shield from Seeedstudio)
 * `SERIAL_SPEED` is the speed of the serial interface. Make sure it matches the settings of whatever software you're using to read the data
 * `CAN_SPEED` should be set to the speed of the CAN bus you're connected too ([possible values](https://github.com/Seeed-Studio/CAN_BUS_Shield#1-set-the-baudrate)).

**Be careful**, setting the wrong speed can mess with the CAN bus. I once set the wrong speed when connecting it to my car and my dashboard lights went crazy! Restarting the car solved the problem, but in any case, *use at your own risk*.

**If you're not using Seeedstudio's shield** you may have to tweak the library to make it work. I had another MCP2515 board and could not make it work with Seeedstudio's library. This was due to the oscillator's frequency. Seeedstudio's shield uses a 16Mhz oscillator, whereas some boards use 10Mhz or some other value. So you need to use [Kvaser's bit timing calculator](https://www.kvaser.com/support/calculators/bit-timing-calculator/) and change the `CFG1`, `CFG2` and `CFG3` variables for your bus speed near the bottom of `mcp_can_dfs.h`.
