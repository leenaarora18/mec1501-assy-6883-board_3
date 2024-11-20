/*
 * Copyright (c) 2016 Open-RnD Sp. z o.o.
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

// #include <zephyr/kernel.h>
// #include <zephyr/device.h>
// #include <zephyr/drivers/gpio.h>
// #include <zephyr/sys/util.h>
// #include <zephyr/sys/printk.h>
// #include <inttypes.h>

// #define SLEEP_TIME_MS	1

// /*
//  * Get button configuration from the devicetree sw0 alias. This is mandatory.
//  */          
// #define SW0_NODE	DT_ALIAS(sw0)
// #if !DT_NODE_HAS_STATUS(SW0_NODE, okay)
// #error "Unsupported board: sw0 devicetree alias is not defined"
// #endif 
// static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios,
// 							      {0});
// static struct gpio_callback button_cb_data;

// /*
//  * The led0 devicetree alias is optional. If present, we'll use it
//  * to turn on the LED whenever the button is pressed.
//  */
// static struct gpio_dt_spec led = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led0), gpios,
// 						     {0});

// void button_pressed(const struct device *dev, struct gpio_callback *cb,
// 		    uint32_t pins)
// {
// 	printk("Button pressed at %" PRIu32 "\n", k_cycle_get_32());
// }

// int main(void)
// {
// 	int ret;

// 	if (!gpio_is_ready_dt(&button)) {
// 		printk("Error: button device %s is not ready\n",
// 		       button.port->name);
// 		return 0;
// 	}

// 	ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
// 	if (ret != 0) {
// 		printk("Error %d: failed to configure %s pin %d\n",
// 		       ret, button.port->name, button.pin);
// 		return 0;
// 	}

// 	ret = gpio_pin_interrupt_configure_dt(&button,
// 					      GPIO_INT_EDGE_TO_ACTIVE);
// 	if (ret != 0) {
// 		printk("Error %d: failed to configure interrupt on %s pin %d\n",
// 			ret, button.port->name, button.pin);
// 		return 0;
// 	}

// 	gpio_init_callback(&button_cb_data, button_pressed, BIT(button.pin));
// 	gpio_add_callback(button.port, &button_cb_data);
// 	printk("Set up button at %s pin %d\n", button.port->name, button.pin);

// 	if (led.port && !gpio_is_ready_dt(&led)) {
// 		printk("Error %d: LED device %s is not ready; ignoring it\n",
// 		       ret, led.port->name);
// 		led.port = NULL;
// 	}
// 	if (led.port) {
// 		ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT);
// 		if (ret != 0) {
// 			printk("Error %d: failed to configure LED device %s pin %d\n",
// 			       ret, led.port->name, led.pin);
// 			led.port = NULL;
// 		} else {
// 			printk("Set up LED at %s pin %d\n", led.port->name, led.pin);
// 		}
// 	}

// 	printk("Press the button\n");
// 	if (led.port) {
// 		while (1) {
// 			/* If we have an LED, match its state to the button's. */
// 			int val = gpio_pin_get_dt(&button);

// 			if (val >= 0) {
// 				gpio_pin_set_dt(&led, val);
// 			}
// 			k_msleep(SLEEP_TIME_MS);
// 		}
// 	}
// 	return 0;
// }




// #include <zephyr/kernel.h>
// #include <zephyr/device.h>
// #include <zephyr/drivers/gpio.h>
// #include <zephyr/sys/util.h>
// #include <zephyr/sys/printk.h>
// #include <inttypes.h>

// #define SLEEP_TIME_MS 1

// /* Get button configuration from the devicetree sw0 alias */
// #define SW0_NODE DT_ALIAS(sw0)

// #if !DT_NODE_HAS_STATUS(SW0_NODE, okay)
// #error "Unsupported board: sw0 devicetree alias is not defined"
// #endif 
// static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios, {0});
// static struct gpio_callback button_cb_data;

// /* Define LED configurations from the devicetree led0, led1, and led2 aliases */
// static struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led0), gpios, {0});
// static struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led1), gpios, {0});
// static struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led2), gpios, {0});

// void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
// {
//     printk("Button pressed at %" PRIu32 "\n", k_cycle_get_32());
// }

// int main(void)
// {
//     int ret;

//     /* Check if button device is ready */
//     if (!gpio_is_ready_dt(&button)) {
//         printk("Error: button device %s is not ready\n", button.port->name);
//         return 0;
//     }

//     /* Configure button as input */
//     ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
//     if (ret != 0) {
//         printk("Error %d: failed to configure %s pin %d\n", ret, button.port->name, button.pin);
//         return 0;
//     }

//     /* Configure button interrupt */
//     ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);
//     if (ret != 0) {
//         printk("Error %d: failed to configure interrupt on %s pin %d\n", ret, button.port->name, button.pin);
//         return 0;
//     }

//     /* Initialize button callback */
//     gpio_init_callback(&button_cb_data, button_pressed, BIT(button.pin));
//     gpio_add_callback(button.port, &button_cb_data);
//     printk("Set up button at %s pin %d\n", button.port->name, button.pin);

//     /* Check if LED devices are ready and configure them as outputs */
//     if (led0.port && !gpio_is_ready_dt(&led0)) {
//         printk("Error: LED0 device %s is not ready\n", led0.port->name);
//         led0.port = NULL;
//     }
//     if (led1.port && !gpio_is_ready_dt(&led1)) {
//         printk("Error: LED1 device %s is not ready\n", led1.port->name);
//         led1.port = NULL;
//     }
//     if (led2.port && !gpio_is_ready_dt(&led2)) {
//         printk("Error: LED2 device %s is not ready\n", led2.port->name);
//         led2.port = NULL;
//     }

//     if (led0.port) {
//         ret = gpio_pin_configure_dt(&led0, GPIO_OUTPUT);
//         if (ret != 0) {
//             printk("Error %d: failed to configure LED0 device %s pin %d\n", ret, led0.port->name, led0.pin);
//             led0.port = NULL;
//         } else {
//             printk("Set up LED0 at %s pin %d\n", led0.port->name, led0.pin);
//         }
//     }

//     if (led1.port) {
//         ret = gpio_pin_configure_dt(&led1, GPIO_OUTPUT);
//         if (ret != 0) {
//             printk("Error %d: failed to configure LED1 device %s pin %d\n", ret, led1.port->name, led1.pin);
//             led1.port = NULL;
//         } else {
//             printk("Set up LED1 at %s pin %d\n", led1.port->name, led1.pin);
//         }
//     }
    
//     if (led2.port) {
//         ret = gpio_pin_configure_dt(&led2, GPIO_OUTPUT);
//         if (ret != 0) {
//             printk("Error %d: failed to configure LED2 device %s pin %d\n", ret, led2.port->name, led2.pin);
//             led2.port = NULL;
//         } else {
//             printk("Set up LED2 at %s pin %d\n", led2.port->name, led2.pin);
//         }
//     }

//     printk("Press the button\n");

//     /* Main loop to set LED states based on button state */
//     while (1) {
//         /* Read the button state */
//         int val = gpio_pin_get_dt(&button);

//         /* Set each LED to match the button's state and print the LED state */
//         if (led0.port) {
//             gpio_pin_set_dt(&led0, val);
//             printk("LED0 state set to %d\n", val);
//         } 

//         if (led1.port) {
//             gpio_pin_set_dt(&led1, val);
//             printk("LED1 state set to %d\n", val);
//         }
//         if (led2.port) {
//             gpio_pin_set_dt(&led2, val);
//             printk("LED2 state set to %d\n", val);
//         }

//         /* Sleep for a short time to prevent excessive CPU usage */
//         k_msleep(SLEEP_TIME_MS);
//     }

//     return 0;
// }



// #include <zephyr/kernel.h>
// #include <zephyr/device.h>
// #include <zephyr/drivers/gpio.h>
// #include <zephyr/sys/util.h>
// #include <zephyr/sys/printk.h>
// #include <inttypes.h>

// #define SLEEP_TIME_MS 1

// /* Define button aliases for sw0, sw1, sw2, and sw3 */
// #define SW0_NODE DT_ALIAS(sw0)
// #define SW1_NODE DT_ALIAS(sw1)
// #define SW2_NODE DT_ALIAS(sw2)
// #define SW3_NODE DT_ALIAS(sw3)

// #if !DT_NODE_HAS_STATUS(SW0_NODE, okay) && !DT_NODE_HAS_STATUS(SW1_NODE, okay) && !DT_NODE_HAS_STATUS(SW2_NODE, okay) && !DT_NODE_HAS_STATUS(SW3_NODE, okay)
// #error "Unsupported board: none of the button devicetree aliases are defined"
// #endif

// /* Define the GPIO button devices */
// static const struct gpio_dt_spec button_sw0 = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios, {0});
// static const struct gpio_dt_spec button_sw1 = GPIO_DT_SPEC_GET_OR(SW1_NODE, gpios, {0});
// static const struct gpio_dt_spec button_sw2 = GPIO_DT_SPEC_GET_OR(SW2_NODE, gpios, {0});
// static const struct gpio_dt_spec button_sw3 = GPIO_DT_SPEC_GET_OR(SW3_NODE, gpios, {0});

// static struct gpio_callback button_sw0_cb_data;
// static struct gpio_callback button_sw1_cb_data;
// static struct gpio_callback button_sw2_cb_data;
// static struct gpio_callback button_sw3_cb_data;

// static struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led0), gpios, {0});
// static struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led1), gpios, {0});
// static struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led2), gpios, {0});

// void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
// {
//     printk("A button was pressed, turning on all LEDs.\n");

//     /* Turn on all LEDs when any button is pressed */
//     if (led0.port) {
//         gpio_pin_set_dt(&led0, 1); // Turn on LED0
//     }

//     if (led1.port) {
//         gpio_pin_set_dt(&led1, 1); // Turn on LED1
//     }

//     if (led2.port) {
//         gpio_pin_set_dt(&led2, 1); // Turn on LED2
//     }
// }

// int main(void)
// {
//     int ret;

//     /* Configure all buttons */
//     const struct gpio_dt_spec buttons[] = {button_sw0, button_sw1, button_sw2, button_sw3};
//     struct gpio_callback *callbacks[] = {&button_sw0_cb_data, &button_sw1_cb_data, &button_sw2_cb_data, &button_sw3_cb_data};

//     for (int i = 0; i < 4; i++) {
//         // if (!gpio_is_ready_dt(&buttons[i])) {
//         //     printk("Error: button %d device %s is not ready\n", i, buttons[i].port->name);
//         //     return 0;
//         // }

//         /* Configure button as input */
//         ret = gpio_pin_configure_dt(&buttons[i], GPIO_INPUT);
//         if (ret != 0) {
//             printk("Error %d: failed to configure button %d pin %d\n", ret, i, buttons[i].pin);
//             return 0;
//         }

//         /* Configure button interrupt */
//         ret = gpio_pin_interrupt_configure_dt(&buttons[i], GPIO_INT_EDGE_TO_ACTIVE);
//         if (ret != 0) {
//             printk("Error %d: failed to configure interrupt on button %d pin %d\n", ret, i, buttons[i].pin);
//             return 0;
//         }

//         /* Initialize button callback */
//         gpio_init_callback(callbacks[i], button_pressed, BIT(buttons[i].pin));
//         gpio_add_callback(buttons[i].port, callbacks[i]);
//         printk("Set up button SW%d at %s pin %d\n", i, buttons[i].port->name, buttons[i].pin);
//     }

//     /* Check if LED devices are ready and configure them as outputs */
//     if (led0.port && !gpio_is_ready_dt(&led0)) {
//         printk("Error: LED0 device %s is not ready\n", led0.port->name);
//         led0.port = NULL;
//     }
//     if (led1.port && !gpio_is_ready_dt(&led1)) {
//         printk("Error: LED1 device %s is not ready\n", led1.port->name);
//         led1.port = NULL;
//     }
//     if (led2.port && !gpio_is_ready_dt(&led2)) {
//         printk("Error: LED2 device %s is not ready\n", led2.port->name);
//         led2.port = NULL;
//     }

//     if (led0.port) {
//         ret = gpio_pin_configure_dt(&led0, GPIO_OUTPUT);
//         if (ret != 0) {
//             printk("Error %d: failed to configure LED0 device %s pin %d\n", ret, led0.port->name, led0.pin);
//             led0.port = NULL;
//         } else {
//             printk("Set up LED0 at %s pin %d\n", led0.port->name, led0.pin);
//         }
//     }

//     if (led1.port) {
//         ret = gpio_pin_configure_dt(&led1, GPIO_OUTPUT);
//         if (ret != 0) {
//             printk("Error %d: failed to configure LED1 device %s pin %d\n", ret, led1.port->name, led1.pin);
//             led1.port = NULL;
//         } else {
//             printk("Set up LED1 at %s pin %d\n", led1.port->name, led1.pin);
//         }
//     }

//     if (led2.port) {
//         ret = gpio_pin_configure_dt(&led2, GPIO_OUTPUT);
//         if (ret != 0) {
//             printk("Error %d: failed to configure LED2 device %s pin %d\n", ret, led2.port->name, led2.pin);
//             led2.port = NULL;
//         } else {
//             printk("Set up LED2 at %s pin %d\n", led2.port->name, led2.pin);
//         }
//     }

//     printk("Press any of the buttons SW0, SW1, SW2, or SW3 to turn on all LEDs\n");

//     /* Main loop to keep checking button states */
//     while (1) {
//         k_msleep(SLEEP_TIME_MS); // Sleep to prevent busy-waiting and excessive CPU usage
//     }

//     return 0;
// }

// #include <zephyr/kernel.h>
// #include <zephyr/device.h>
// #include <zephyr/drivers/gpio.h>
// #include <zephyr/sys/util.h>
// #include <zephyr/sys/printk.h>
// #include <inttypes.h>

// #define SLEEP_TIME_MS 1

// /* Define button aliases for sw0, sw1, sw2, and sw3 */
// #define SW0_NODE DT_ALIAS(sw0)
// #define SW1_NODE DT_ALIAS(sw1)
// #define SW2_NODE DT_ALIAS(sw2)
// #define SW3_NODE DT_ALIAS(sw3)

// #if !DT_NODE_HAS_STATUS(SW0_NODE, okay) && !DT_NODE_HAS_STATUS(SW1_NODE, okay) && !DT_NODE_HAS_STATUS(SW2_NODE, okay) && !DT_NODE_HAS_STATUS(SW3_NODE, okay)
// #error "Unsupported board: none of the button devicetree aliases are defined"
// #endif

// /* Define the GPIO button devices */
// static const struct gpio_dt_spec button_sw0 = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios, {0});
// static const struct gpio_dt_spec button_sw1 = GPIO_DT_SPEC_GET_OR(SW1_NODE, gpios, {0});
// static const struct gpio_dt_spec button_sw2 = GPIO_DT_SPEC_GET_OR(SW2_NODE, gpios, {0});
// static const struct gpio_dt_spec button_sw3 = GPIO_DT_SPEC_GET_OR(SW3_NODE, gpios, {0});

// static struct gpio_callback button_sw0_cb_data;
// static struct gpio_callback button_sw1_cb_data;
// static struct gpio_callback button_sw2_cb_data;
// static struct gpio_callback button_sw3_cb_data;

// static struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led0), gpios, {0});
// static struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led1), gpios, {0});
// static struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led2), gpios, {0});

// void button_sw0_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
// {
//     printk("Button SW0 pressed at %" PRIu32 "\n", k_cycle_get_32());
// }

// void button_sw1_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
// {
//     printk("Button SW1 pressed at %" PRIu32 "\n", k_cycle_get_32());
// }

// void button_sw2_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
// {
//     printk("Button SW2 pressed at %" PRIu32 "\n", k_cycle_get_32());
// }

// void button_sw3_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
// {
//     printk("Button SW3 pressed at %" PRIu32 "\n", k_cycle_get_32());
// }

// int main(void)
// {
//     int ret;

//     /* Configure all buttons */
//     const struct gpio_dt_spec buttons[] = {button_sw0, button_sw1, button_sw2, button_sw3};
//     struct gpio_callback *callbacks[] = {&button_sw0_cb_data, &button_sw1_cb_data, &button_sw2_cb_data, &button_sw3_cb_data};

//     for (int i = 0; i < 4; i++) {
//         if (!gpio_is_ready_dt(&buttons[i])) {
//             printk("Error: button %d device %s is not ready\n", i, buttons[i].port->name);
//             return 0;
//         }

//         /* Configure button as input */
//         ret = gpio_pin_configure_dt(&buttons[i], GPIO_INPUT);
//         if (ret != 0) {
//             printk("Error %d: failed to configure button %d pin %d\n", ret, i, buttons[i].pin);
//             return 0;
//         }

//         /* Configure button interrupt */
//         ret = gpio_pin_interrupt_configure_dt(&buttons[i], GPIO_INT_EDGE_TO_ACTIVE);
//         if (ret != 0) {
//             printk("Error %d: failed to configure interrupt on button %d pin %d\n", ret, i, buttons[i].pin);
//             return 0;
//         }
        
//         /* Initialize button callback */
//         gpio_init_callback(callbacks[i], button_sw0_pressed, BIT(buttons[i].pin));
//         gpio_add_callback(buttons[i].port, callbacks[i]);
//         printk("Set up button SW%d at %s pin %d\n", i, buttons[i].port->name, buttons[i].pin);
//     }

//     /* Check if LED devices are ready and configure them as outputs */
//     if (led0.port && !gpio_is_ready_dt(&led0)) {
//         printk("Error: LED0 device %s is not ready\n", led0.port->name);
//         led0.port = NULL;
//     }
//     if (led1.port && !gpio_is_ready_dt(&led1)) {
//         printk("Error: LED1 device %s is not ready\n", led1.port->name);
//         led1.port = NULL;
//     }
//     if (led2.port && !gpio_is_ready_dt(&led2)) {
//         printk("Error: LED2 device %s is not ready\n", led2.port->name);
//         led2.port = NULL;
//     }

//     if (led0.port) {
//         ret = gpio_pin_configure_dt(&led0, GPIO_OUTPUT);
//         if (ret != 0) {
//             printk("Error %d: failed to configure LED0 device %s pin %d\n", ret, led0.port->name, led0.pin);
//             led0.port = NULL;
//         } else {
//             printk("Set up LED0 at %s pin %d\n", led0.port->name, led0.pin);
//         }
//     }

//     if (led1.port) {
//         ret = gpio_pin_configure_dt(&led1, GPIO_OUTPUT);
//         if (ret != 0) {
//             printk("Error %d: failed to configure LED1 device %s pin %d\n", ret, led1.port->name, led1.pin);
//             led1.port = NULL;
//         } else {
//             printk("Set up LED1 at %s pin %d\n", led1.port->name, led1.pin);
//         }
//     }

//     if (led2.port) {
//         ret = gpio_pin_configure_dt(&led2, GPIO_OUTPUT);
//         if (ret != 0) {
//             printk("Error %d: failed to configure LED2 device %s pin %d\n", ret, led2.port->name, led2.pin);
//             led2.port = NULL;
//         } else {
//             printk("Set up LED2 at %s pin %d\n", led2.port->name, led2.pin);
//         }
//     }

//     printk("Press the buttons SW0, SW1, SW2, or SW3\n");

//     /* Main loop to set LED states based on button state */
//     while (1) {
//         for (int i = 0; i < 4; i++) {
//             /* Read the button state */
//             int val = gpio_pin_get_dt(&buttons[i]);

//             /* Set each LED to match the button's state and print the LED state */
//             if (led0.port) {
//                 gpio_pin_set_dt(&led0, val);
//                 printk("LED0 state set to %d based on SW%d\n", val, i);
//             }

//             if (led1.port) {
//                 gpio_pin_set_dt(&led1, val);
//                 printk("LED1 state set to %d based on SW%d\n", val, i);
//             }

//             if (led2.port) {
//                 gpio_pin_set_dt(&led2, val);
//                 printk("LED2 state set to %d based on SW%d\n", val, i);
//             }
//         }

//         /* Sleep for a short time to prevent excessive CPU usage */
//         k_msleep(SLEEP_TIME_MS);
//     }

//     return 0;
// }


// #include <zephyr/kernel.h>
// #include <zephyr/device.h>
// #include <zephyr/drivers/gpio.h>
// #include <zephyr/sys/util.h>
// #include <zephyr/sys/printk.h>
// #include <inttypes.h>
// #define SLEEP_TIME_MS 1


// /* Define possible GPIO controllers for buttons */
// //#define GPIO_CONTROLLERS { "gpio_000_036", "gpio_040_076", "gpio_100_136", "gpio_140_176" }
// /* Define possible GPIO controller labels as per .dts file */
// #define GPIO_CONTROLLERS {"gpio_240_276", "gpio_000_036", "gpio_200_236", "gpio_040_076" }

// /* Define button aliases for sw0, sw1, sw2, and sw3 */
// #define SW0_NODE DT_ALIAS(sw0)
// #define SW1_NODE DT_ALIAS(sw1)
// #define SW2_NODE DT_ALIAS(sw2)
// #define SW3_NODE DT_ALIAS(sw3)

// #if !DT_NODE_HAS_STATUS(SW0_NODE, okay) && !DT_NODE_HAS_STATUS(SW1_NODE, okay) && !DT_NODE_HAS_STATUS(SW2_NODE, okay) && !DT_NODE_HAS_STATUS(SW3_NODE, okay)
// #error "Unsupported board: none of the button devicetree aliases are defined"
// #endif

// /* Define the GPIO button devices */
// static struct gpio_dt_spec buttons[] = {
//     GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios, {0}),
//     GPIO_DT_SPEC_GET_OR(SW1_NODE, gpios, {0}),
//     GPIO_DT_SPEC_GET_OR(SW2_NODE, gpios, {0}),
//     GPIO_DT_SPEC_GET_OR(SW3_NODE, gpios, {0})
// };

// /* Define GPIO controllers to test */
// const char *gpio_controllers[] = GPIO_CONTROLLERS;
// static struct gpio_callback button_cb_data[4];

// void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
// {
//     printk("Button pressed on port %s at %" PRIu32 "\n", dev->name, k_cycle_get_32());
// }

// int try_configure_button(struct gpio_dt_spec *button)
// {
//     int ret;
//     /* Try to configure each GPIO controller for the button */
//     for (int i = 0; i < ARRAY_SIZE(gpio_controllers); i++) {
//         button->port = device_get_binding(gpio_controllers[i]);
//         if (!button->port) {
//             printk("Error: GPIO controller %s not found\n", gpio_controllers[i]);
//             continue;
//         }
        
//         /* Configure button as input */
//         ret = gpio_pin_configure_dt(button, GPIO_INPUT);
//         if (ret == 0) {
//             printk("Configured button on %s pin %d\n", gpio_controllers[i], button->pin);
//             return 0;
//         }
//     }
//     printk("Error: Could not configure button pin %d\n", button->pin);
//     return -1;
// }

// int main(void)
// {
//     int ret;
//     /* Attempt to configure all buttons */
//     for (int i = 0; i < ARRAY_SIZE(buttons); i++) {
//         ret = try_configure_button(&buttons[i]);
//         if (ret != 0) {
//             printk("Error configuring button %d\n", i);    
//             continue; 
//         }
        
//         /* Configure button interrupt */
//         ret = gpio_pin_interrupt_configure_dt(&buttons[i], GPIO_INT_EDGE_TO_ACTIVE);
//         if (ret != 0) {
//             printk("Error %d: failed to configure interrupt on button %d pin %d\n", ret, i, buttons[i].pin);
//             continue;
//         }

//         /* Initialize button callback */
//         gpio_init_callback(&button_cb_data[i], button_pressed, BIT(buttons[i].pin));
//         gpio_add_callback(buttons[i].port, &button_cb_data[i]);
//         printk("Set up button SW%d on %s pin %d\n", i, buttons[i].port->name, buttons[i].pin);
//     }

//     printk("Press any configured button to see results\n");   

//     /* Main loop */
//     while (1) {
//         /* Code to monitor button state or manage LEDs here if needed */
//         k_msleep(SLEEP_TIME_MS);
//     }

//     return 0;
// }


// #include <zephyr/kernel.h>
// #include <zephyr/device.h>
// #include <zephyr/drivers/gpio.h>
// #include <zephyr/sys/printk.h>
// #include <inttypes.h>

// #define SLEEP_TIME_MS 1

// /* Define button alias for sw0 */
// #define SW0_NODE DT_ALIAS(sw0)

// #if !DT_NODE_HAS_STATUS(SW0_NODE, okay)
// #error "Unsupported board: sw0 devicetree alias is not defined"
// #endif

// /* Define the GPIO button device */
// static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios, {0});

// /* Define GPIO callback */
// static struct gpio_callback button_cb_data;

// /* Button press callback function */
// void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
// {
//     printk("Button pressed on %s at %" PRIu32 "\n", dev->name, k_cycle_get_32());
// }

// void main(void)
// {
//     int ret;

//     if (!device_is_ready(button.port)) {
//         printk("Error: Button device %s is not ready\n", button.port->name);
//         return;
//     }

//     /* Configure the button pin as input */
//     ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
//     if (ret != 0) {
//         printk("Error %d: Failed to configure button pin %d\n", ret, button.pin);
//         return;
//     }

//     /* Configure interrupt for the button pin */
//     ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);
//     if (ret != 0) {
//         printk("Error %d: Failed to configure interrupt for pin %d\n", ret, button.pin);
//         return;
//     }

//     /* Initialize button callback */
//     gpio_init_callback(&button_cb_data, button_pressed, BIT(button.pin));
//     gpio_add_callback(button.port, &button_cb_data);

//     printk("Button configured: %s pin %d\n", button.port->name, button.pin);
//     printk("Press the button to trigger an interrupt.\n");

//     /* Main loop */
//     while (1) {
//         k_msleep(SLEEP_TIME_MS);
//     }
// }



#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>
#include <inttypes.h>

#define SLEEP_TIME_MS 1

/* Button and LED aliases from the devicetree */
#define SW0_NODE DT_ALIAS(sw0)
#define LED0_NODE DT_ALIAS(led1)

#if !DT_NODE_HAS_STATUS(SW0_NODE, okay)
#error "Unsupported board: button alias 'sw0' not defined in the device tree"
#endif

#if !DT_NODE_HAS_STATUS(LED0_NODE, okay)
#error "Unsupported board: LED alias 'led0' not defined in the device tree"
#endif

/* Define button and LED devices */
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios, {0});
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET_OR(LED0_NODE, gpios, {0});

/* GPIO callback structure */
static struct gpio_callback button_cb_data;

/* Button pressed callback function */
void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
    printk("Button pressed on %s at %" PRIu32 "\n", dev->name, k_cycle_get_32());
    printk("inside the button Interuppt");
    /* Toggle the LED */
    gpio_pin_toggle_dt(&led);       
}

int main(void)
{
    int ret;
      printk("Hello Surjit");
    /* Configure the LED as an output */
    if (!device_is_ready(led.port)) {
        printk("Error: LED device %s is not ready\n", led.port->name);
        return -1;
    }
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret != 0) {
        printk("Error %d: failed to configure LED %s pin %d\n", ret, led.port->name, led.pin);
        return ret;
    }

    /* Configure the button as an input with interrupt */
    if (!device_is_ready(button.port)) {
        printk("Error: Button device %s is not ready\n", button.port->name);
        return -1;
    }
    ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
    if (ret != 0) {
        printk("Error %d: failed to configure button %s pin %d\n", ret, button.port->name, button.pin);
        return ret;
    }
    ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);
    if (ret != 0) {
        printk("Error %d: failed to configure interrupt for button %s pin %d\n", ret, button.port->name, button.pin);
        return ret;
    }

    /* Initialize button callback */
    gpio_init_callback(&button_cb_data, button_pressed, BIT(button.pin));
    gpio_add_callback(button.port, &button_cb_data);
    printk("Set up button on %s pin %d\n", button.port->name, button.pin);
    printk("Set up LED on %s pin %d\n", led.port->name, led.pin);

    /* Main loop */
    while (1) {
        k_msleep(SLEEP_TIME_MS);
    }

    return 0;
}
