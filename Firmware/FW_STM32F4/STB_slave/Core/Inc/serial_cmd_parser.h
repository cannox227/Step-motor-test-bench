/*
 * serial_cmd_parser.h
 *
 *  Created on: Aug 5, 2022
 *      Author: macbookpro
 */

#ifndef INC_SERIAL_CMD_PARSER_H_
#define INC_SERIAL_CMD_PARSER_H_

#include "main.h"
#include "app_threadx.h"
#include "usart.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MOTOR_CMD_SIZE 2
#define MOTOR_CMD_PARAM_SIZE 6
#define MOTOR_CMD_PADDING 3
#define RX_BUFF_SIZE (MOTOR_CMD_SIZE+ MOTOR_CMD_PARAM_SIZE+MOTOR_CMD_PADDING) //11
#define TX_BUFF_SIZE 300

typedef struct{
	bool is_cmd_received;
	char cmd_received[RX_BUFF_SIZE];
	motor_cmd_msg msg;
} serial_handler;


extern serial_handler STM_handler;
extern serial_handler STG_handler;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart3);
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
void build_cmd(serial_handler* handler);
bool parse_cmd(TX_QUEUE *ptr_motor_queue, serial_handler* handler);

#endif /* INC_SERIAL_CMD_PARSER_H_ */