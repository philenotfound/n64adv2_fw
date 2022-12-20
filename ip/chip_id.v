// megafunction wizard: %Unique Chip ID Intel FPGA IP v22.1%
// GENERATION: XML
// chip_id.v

// Generated using ACDS version 22.1 915

`timescale 1 ps / 1 ps
module chip_id (
		input  wire        clkin,      //  clkin.clk
		input  wire        reset,      //  reset.reset
		output wire        data_valid, // output.valid
		output wire [63:0] chip_id     //       .data
	);

	altchip_id #(
		.DEVICE_FAMILY ("MAX 10"),
		.ID_VALUE      (64'b1111111111111111111111111111111111111111111111111111111111111111),
		.ID_VALUE_STR  ("00000000ffffffff")
	) chip_id_inst (
		.clkin      (clkin),      //  clkin.clk
		.reset      (reset),      //  reset.reset
		.data_valid (data_valid), // output.valid
		.chip_id    (chip_id)     //       .data
	);

endmodule
// Retrieval info: <?xml version="1.0"?>
//<!--
//	Generated by Altera MegaWizard Launcher Utility version 1.0
//	************************************************************
//	THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
//	************************************************************
//	Copyright (C) 1991-2022 Altera Corporation
//	Any megafunction design, and related net list (encrypted or decrypted),
//	support information, device programming or simulation file, and any other
//	associated documentation or information provided by Altera or a partner
//	under Altera's Megafunction Partnership Program may be used only to
//	program PLD devices (but not masked PLD devices) from Altera.  Any other
//	use of such megafunction design, net list, support information, device
//	programming or simulation file, or any other related documentation or
//	information is prohibited for any other purpose, including, but not
//	limited to modification, reverse engineering, de-compiling, or use with
//	any other silicon devices, unless such use is explicitly licensed under
//	a separate agreement with Altera or a megafunction partner.  Title to
//	the intellectual property, including patents, copyrights, trademarks,
//	trade secrets, or maskworks, embodied in any such megafunction design,
//	net list, support information, device programming or simulation file, or
//	any other related documentation or information provided by Altera or a
//	megafunction partner, remains with Altera, the megafunction partner, or
//	their respective licensors.  No other licenses, including any licenses
//	needed under any third party's intellectual property, are provided herein.
//-->
// Retrieval info: <instance entity-name="altchip_id" version="22.1" >
// Retrieval info: 	<generic name="DEVICE_FAMILY" value="MAX 10" />
// Retrieval info: 	<generic name="ID_VALUE" value="18446744073709551615" />
// Retrieval info: </instance>
// IPFS_FILES : chip_id.vo
// RELATED_FILES: chip_id.v, altchip_id.v
