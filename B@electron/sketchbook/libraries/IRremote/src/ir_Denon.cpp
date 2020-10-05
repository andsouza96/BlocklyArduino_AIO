#include "IRremote.h"

// Reverse Engineered by looking at RAW dumps generated by IRremote

// I have since discovered that Denon publish all their IR codes:
//  https://www.google.co.uk/search?q=DENON+MASTER+IR+Hex+Command+Sheet
//  -> http://assets.denon.com/documentmaster/us/denon%20master%20ir%20hex.xls

// Having looked at the official Denon Pronto sheet and reverse engineered
// the timing values from it, it is obvious that Denon have a range of
// different timings and protocols ...the values here work for my AVR-3801 Amp!

//==============================================================================
//                    DDDD   EEEEE  N   N   OOO   N   N
//                     D  D  E      NN  N  O   O  NN  N
//                     D  D  EEE    N N N  O   O  N N N
//                     D  D  E      N  NN  O   O  N  NN
//                    DDDD   EEEEE  N   N   OOO   N   N
//==============================================================================

#define DENON_BITS            14  // The number of bits in the command

#define DENON_HEADER_MARK    300  // The length of the Header:Mark
#define DENON_HEADER_SPACE   750  // The lenght of the Header:Space

#define DENON_BIT_MARK       300  // The length of a Bit:Mark
#define DENON_ONE_SPACE     1800  // The length of a Bit:Space for 1's
#define DENON_ZERO_SPACE     750  // The length of a Bit:Space for 0's

//+=============================================================================
//
#if SEND_DENON
void IRsend::sendDenon(unsigned long data, int nbits) {
    // Set IR carrier frequency
    enableIROut(38);

    // Header
    mark(DENON_HEADER_MARK);
    space(DENON_HEADER_SPACE);

    // Data
    sendPulseDistanceWidthData(DENON_BIT_MARK, DENON_ONE_SPACE, DENON_BIT_MARK, DENON_ZERO_SPACE, data, nbits);
//    for (unsigned long mask = 1UL << (nbits - 1); mask; mask >>= 1) {
//        if (data & mask) {
//            mark(DENON_BIT_MARK);
//            space(DENON_ONE_SPACE);
//        } else {
//            mark(DENON_BIT_MARK);
//            space(DENON_ZERO_SPACE);
//        }
//    }

// Footer
    mark(DENON_BIT_MARK);
    space(0);  // Always end with the LED off
}
#endif

//+=============================================================================
//
#if DECODE_DENON
bool IRrecv::decodeDenon() {
    unsigned long data = 0;  // Somewhere to build our code
    int offset = 1;  // Skip the gap reading

    // Check we have the right amount of data
    if (irparams.rawlen != 1 + 2 + (2 * DENON_BITS) + 1) {
        return false;
    }

    // Check initial Mark+Space match
    if (!MATCH_MARK(results.rawbuf[offset], DENON_HEADER_MARK)) {
        return false;
    }
    offset++;

    if (!MATCH_SPACE(results.rawbuf[offset], DENON_HEADER_SPACE)) {
        return false;
    }
    offset++;

    // Read the bits in
    data = decodePulseDistanceData(DENON_BITS, offset, DENON_BIT_MARK, DENON_ONE_SPACE, DENON_ZERO_SPACE);
//    for (int i = 0; i < DENON_BITS; i++) {
//        // Each bit looks like: MARK + SPACE_1 -> 1
//        //                 or : MARK + SPACE_0 -> 0
//        if (!MATCH_MARK(results.rawbuf[offset], DENON_BIT_MARK)) {
//            return false;
//        }
//        offset++;
//
//        // IR data is big-endian, so we shuffle it in from the right:
//        if (MATCH_SPACE(results.rawbuf[offset], DENON_ONE_SPACE)) {
//            data = (data << 1) | 1;
//        } else if (MATCH_SPACE(results.rawbuf[offset], DENON_ZERO_SPACE)) {
//            data = (data << 1) | 0;
//        } else {
//            return false;
//        }
//        offset++;
//    }

    // Success
    results.bits = DENON_BITS;
    results.value = data;
    results.decode_type = DENON;
    return true;
}
bool IRrecv::decodeDenon(decode_results *aResults) {
    bool aReturnValue = decodeDenon();
    *aResults = results;
    return aReturnValue;
}
#endif
