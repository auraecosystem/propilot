/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.
 * See the NOTICE file distributed with this work
 * for additional information regarding copyright ownership.
 *
 * The ASF licenses this file to You under the Apache License, Version 2.0.
 */

package org.apache.beam.learning.katas.windowing.fixedwindow

import java.io.Serializable
import java.time.Instant

/**
 * Represents an event that has been assigned to a Beam window.
 */
data class WindowedEvent(

    /** Event identifier or payload */
    val event: String = "",

    /** Number of occurrences */
    val count: Long = 0L,

    /** Window label */
    val window: String = "",

    /** Event timestamp */
    val timestamp: Instant = Instant.now(),

    /** Processing time */
    val processedAt: Instant = Instant.now(),

    /** Optional metadata */
    val metadata: Map<String, String> = emptyMap()

) : Serializable {

    companion object {
        private const val serialVersionUID: Long = 1L
    }

    /**
     * Returns true if this record contains a valid event.
     */
    fun isValid(): Boolean =
        event.isNotBlank() &&
        count >= 0 &&
        window.isNotBlank()

    /**
     * Returns a human-readable summary.
     */
    fun summary(): String =
        "WindowedEvent(event='$event', count=$count, window='$window')"

    /**
     * Creates a copy with an updated count.
     */
    fun increment(by: Long = 1): WindowedEvent =
        copy(count = count + by)
}
