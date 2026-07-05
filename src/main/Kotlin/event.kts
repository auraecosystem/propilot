package org.apache.beam.learning.katas.windowing.fixedwindow

import java.io.Serializable
import java.time.Instant
import java.util.UUID

data class WindowedEvent(

    /** Unique event ID */
    val id: String = UUID.randomUUID().toString(),

    /** Event name */
    val event: String = "",

    /** Event category */
    val category: String = "general",

    /** Number of events */
    val count: Long = 0L,

    /** Fixed window label */
    val window: String = "",

    /** Event timestamp */
    val eventTime: Instant = Instant.now(),

    /** Processing timestamp */
    val processingTime: Instant = Instant.now(),

    /** Source system */
    val source: String = "unknown",

    /** User identifier */
    val userId: String? = null,

    /** Arbitrary metadata */
    val metadata: Map<String, String> = emptyMap(),

    /** Numeric metrics */
    val metrics: Map<String, Double> = emptyMap(),

    /** Tags */
    val tags: List<String> = emptyList()

) : Serializable {

    companion object {
        private const val serialVersionUID = 1L
    }

    fun increment(by: Long = 1): WindowedEvent =
        copy(count = count + by)

    fun addTag(tag: String): WindowedEvent =
        copy(tags = tags + tag)

    fun addMetric(name: String, value: Double): WindowedEvent =
        copy(metrics = metrics + (name to value))

    fun addMetadata(key: String, value: String): WindowedEvent =
        copy(metadata = metadata + (key to value))

    fun isValid(): Boolean =
        event.isNotBlank() &&
        count >= 0 &&
        window.isNotBlank()

    fun summary(): String =
        """
        WindowedEvent(
            id=$id,
            event=$event,
            category=$category,
            count=$count,
            window=$window,
            source=$source
        )
        """.trimIndent()
}
