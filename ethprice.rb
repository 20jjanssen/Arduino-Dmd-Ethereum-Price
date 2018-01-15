require "net/http"
require "json"
require "serialport"
require "cryptocompare"

loop do
    port_str = "/dev/tty.usbmodem1441"  #NB port may be different for you, copy this from port selected in Arduino IDE 
        baud_rate = 9600
        data_bits = 8
        stop_bits = 1
        parity = SerialPort::NONE

    sp = SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)
    url = 'https://min-api.cryptocompare.com/data/price?fsym=ETH&tsyms=AUD'
    uri = URI(url)
    response = Net::HTTP.get(uri)
    data_hash = JSON.parse(response)
    sp.write '1 Eth = $' 
    sp.write data_hash["AUD"]
    sp.write ' AUD'
    sleep(15)
end